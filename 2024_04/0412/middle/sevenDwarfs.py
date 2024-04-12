def main():
    arr = [0] * 9
    sum = 0
    for i in range(9):
        arr[i] = int(input())
        sum += arr[i]

    # 높이 계산
    height = sum - 100
    notD1 = 0
    notD2 = 0

    for i in range(9):
        for j in range(i + 1, 9):
            if (arr[i] + arr[j]) == height:
                notD1 = i
                notD2 = j
                break

    real_dwarf = [arr[i] for i in range(9) if i != notD1 and i != notD2]

    real_dwarf.sort()

    for i in range(7):
        print(real_dwarf[i])

if __name__ == "__main__":
    main()
