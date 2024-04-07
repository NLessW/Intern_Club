default_money = 1000
changes_money = 0
count = 0
i = 0
coin = [500, 100, 50, 10, 5, 1]

changes_money = int(input())
default_money -= changes_money

while default_money > 0:
    if default_money >= coin[i]:
        default_money -= coin[i]
        count += 1
    else:
        i += 1

print(count)
