
def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    a = a.splitlines()  # Split string into lines
    b = b.splitlines()
    c = set(a) & set(b)  # Find common elements
    return c                      


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    from nltk.tokenize import sent_tokenize  # Import special library for splitting string into sentences
    a = sent_tokenize(a) # Split string into sentences
    b = sent_tokenize(b)
    c = set(a) & set(b) # Find common elements
    return c         


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO
    split_string = lambda x, n: [x[i:i+n] for i in range(0, (len(x) - n + 1))]
    a = split_string(a, n)
    b = split_string(b, n)
    c = set(a) & set(b)
    return c
