from cs50 import get_int

print("Number: ", end='')
card_number = get_int()
card_number_list = list(map(int, str(card_number)))
leng = len(card_number_list)
j = 1
summ1 = 0
summ2 = 0
summ3 = 0
i = int(leng - 1)
while i >= 0:
    if j % 2 == 0:
        summ1 += int((card_number_list[i] * 2) % 10 + (card_number_list[i] * 2) / 10)
    else:
        summ2 += int(card_number_list[i])
    j += 1
    i -= 1
    summ3 = summ1 + summ2
if card_number_list[0] == 4 and (leng == 13 or leng == 16) and summ3 % 10 == 0:
    print("VISA")
elif card_number_list[0] == 3 and (card_number_list[1] == 4 or card_number_list[1] == 7) and leng == 15 and summ3 % 10 == 0:
    print("AMEX")
elif card_number_list[0] == 5 and (card_number_list[1] == 1 or card_number_list[1] == 2 or card_number_list[1] == 3 or card_number_list[1] == 4 or card_number_list[1] == 5) and leng == 16 and summ3 % 10 == 0:
    print("MASTERCARD")
else:
    print("INVALID")