a = int(input())
b = [input() for _ in range(a)]
c = b[0]

for i in range(1, a):
    for j in range(len(c)):
        if c[j] != '?' and c[j] != b[i][j]:
            c = c[:j] + '?' + c[j + 1:]

print(c)
