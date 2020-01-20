import os, datetime, sqlite3

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp() # creating temporary directory
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    # Updating pricing info
    stocks = db.execute("SELECT id, symbol, price, shares, total FROM stock WHERE id = :user_id",
                         user_id=session["user_id"])
    for stock in stocks:
        price = stock['price']
        symbol = stock['symbol']
        search = lookup(symbol)
        db.execute("UPDATE stock SET price = :price WHERE id = :user_id AND symbol = :symbol",
                        price=search['price'],
                        user_id=session["user_id"],
                        symbol=search['symbol'])
    # Update total value
    db.execute("UPDATE stock SET total = price*shares")
    """Show portfolio of stocks"""
    rows = db.execute("SELECT symbol, name, SUM(shares) as shares1, price as price1, SUM(total) as total1 FROM stock WHERE id = :user_id GROUP BY symbol" ,
                          user_id=session["user_id"])
    balances = db.execute("SELECT cash as cash1 FROM  users WHERE id = :user_id",
                            user_id=session["user_id"])
    overalls = db.execute("SELECT cash+SUM(total) AS total1 FROM (SELECT users.id, users.cash, stock.total FROM users INNER JOIN stock ON users.id=stock.id WHERE stock.id=:user_id AND EXISTS(SELECT * FROM stock))",
                            user_id=session["user_id"])
    const = "CASH"
    return render_template("index.html", rows = rows, const = const, balances = balances, overalls = overalls)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":

        # Ensure symbol is filled
        if not request.form.get("symbol"):
            return apology("must provide symbol name!", 403)

        elif not request.form.get("shares"):
            return apology("must provide number of shares!", 403)

        elif int(request.form.get("shares")) < 0:
            return apology("number of shares must be positive!", 403)

        # Get stock quote
        s = lookup(request.form.get("symbol"))

        # Checking if user can afford to buy symbol
        rows = db.execute("SELECT cash FROM users WHERE id = :user_id",
                          user_id=session["user_id"])

        summary =  s['price']*float(request.form.get("shares"))

        if rows[0]["cash"] < summary:
            return apology("not enough money to buy this stock!", 403)

        # Updating cash
        rows = db.execute("UPDATE users SET cash = :cash WHERE id =  :user_id",
                           cash=rows[0]["cash"] - summary,
                           user_id=session["user_id"])

        # Adding purchase to database
        cows = db.execute("INSERT INTO stock (symbol, name, id, shares, price, total, date) VALUES (:symbol, :name, :user_id, :shares, :price, :total, :date)",
                          symbol=request.form.get("symbol"),
                          name=s['name'],
                          user_id=session["user_id"],
                          shares=request.form.get("shares"),
                          price=s['price'],
                          total=s['price']*float(request.form.get("shares")),
                          date=datetime.datetime.now())

        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":

        # Ensure symbol is filled
        if not request.form.get("symbol"):
            return apology("must provide symbol", 403)

        # Get stock quote
        s = lookup(request.form.get("symbol"))

        try:
            return render_template("quoted.html", name = s['name'], price = usd(s['price']), symbol = s['symbol'])
        except:
            return apology("no such symbol!", 403)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
     # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Ensure passwords are matched
        elif request.form.get("password") != request.form.get("passwordconfirm"):
            return apology("passwords don't match!", 403)

        # Check if username exists
        check = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))
        if len(check) != 0:
            return apology("username already exists!", 403)

        # Add to database
        rows = db.execute("INSERT INTO users (username, hash) VALUES (:username, :passhash)",
                          username=request.form.get("username"),
                          passhash=generate_password_hash(request.form.get("password")))

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
