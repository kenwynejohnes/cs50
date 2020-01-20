from cs50 import get_int

print("Height: ", end='')  # end points remaining user input on the same line as printed statement
while True:
    height = get_int()  # grab user input
    if height < 0 or height > 23:
        print("Height: ", end='')
    else:
        break
for i in range(height):
    for j in range(height - i - 1):
        print(" ", end='')
    for k in range(i + 1):
        print("#", end='')
    print(" ", end='')
    print(" ", end='')
    for k in range(i + 1):
        print("#", end='')
    print("\n", end='')