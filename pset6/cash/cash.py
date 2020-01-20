from cs50 import get_float
import math

print("Change owed: ", end='')
while True:
    change_float = get_float()
    if change_float < 0:
        print("Change owed: ", end='')
    else:
        break
change_int = round(int(change_float * 100))
quarters = int(change_int / 25)
q_remains = change_int % 25
dimes = int(q_remains / 10)
d_remains = q_remains % 10
nickels = int(d_remains / 5)
n_remains = d_remains % 5
pennies = int(n_remains / 1)
coins = quarters + dimes + nickels + pennies
print(coins)



