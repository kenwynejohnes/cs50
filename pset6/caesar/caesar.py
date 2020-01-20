from cs50 import get_string
import sys

if len(sys.argv) != 2:
    print("Usage: ./caesar.py k")
else:
    print("plaintext: ", end='')
    p = get_string()
    print("ciphertext: ", end='')
k = int(sys.argv[1])
leng = len(p)
for i in range(leng):
    if i != leng - 1:
        if p[i].isalpha() == True and p[i].isupper() == True:
            print("{}".format(chr(((ord(p[i]) - 65 + k) % 26) + 65)), end='')
        elif p[i].isalpha() == True and p[i].isupper() == False:
            print("{}".format(chr(((ord(p[i]) - 97 + k) % 26) + 97)), end='')
        else:
            print("{}".format(p[i]), end='')
    else:
        if p[i].isalpha() == True and p[i].isupper() == True:
            print("{}".format(chr(((ord(p[i]) - 65 + k) % 26) + 65)))
        elif p[i].isalpha() == True and p[i].isupper() == False:
            print("{}".format(chr(((ord(p[i]) - 97 + k) % 26) + 97)))
        else:
            print("{}".format(p[i]))
    