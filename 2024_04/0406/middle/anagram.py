count = 0
a1 = [0] * 26
b1 = [0] * 26

a2 = input()
b2 = input()

for c in a2:
    if 'a' <= c <= 'z':
        a1[ord(c) - ord('a')] += 1

for c in b2:
    if 'a' <= c <= 'z':
        b1[ord(c) - ord('a')] += 1

for i in range(26):
    count += abs(a1[i] - b1[i])

print(count)
