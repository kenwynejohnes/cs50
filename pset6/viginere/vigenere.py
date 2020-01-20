from cs50 import get_string
import sys

lenf = len(sys.argv[1])
k = sys.argv[1]

for n in range(lenf):
    if k[n].isalpha() == False or len(sys.argv) != 2:
        print("Usage: ./vigenere.py k")
        exit()
        
print("plaintext: ", end='')
p = get_string()
print("ciphertext: ", end='')   
leng = len(p)
nonaplha = 0
for i in range(leng):
    if i == 0:
        j = i % lenf
    elif p[i - 1].isalpha() == True and i != 0:
        if i > lenf:
            j = (i - nonalpha) % lenf
        else:
            j = i % lenf
    else:
        nonalpha += 1
        j = (i - nonalpha) % lenf

#     if i != leng - 1:
#         if p[i].isalpha() == True and p[i].isupper() == True:
#             print("{}".format(chr(((ord(p[i]) - 65 + k) % 26) + 65)), end='')
#         elif p[i].isalpha() == True and p[i].isupper() == False:
#             print("{}".format(chr(((ord(p[i]) - 97 + k) % 26) + 97)), end='')
#         else:
#             print("{}".format(p[i]), end='')
#     else:
#         if p[i].isalpha() == True and p[i].isupper() == True:
#             print("{}".format(chr(((ord(p[i]) - 65 + k) % 26) + 65)))
#         elif p[i].isalpha() == True and p[i].isupper() == False:
#             print("{}".format(chr(((ord(p[i]) - 97 + k) % 26) + 97)))
#         else:
#             print("{}".format(p[i]))
    