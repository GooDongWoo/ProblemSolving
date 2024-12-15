a = sorted([int(input()) for _ in range(9)])
tot = sum(a)
for i in range(8):
    for j in range(i, 9):
        if a[i] + a[j] == tot - 100:
            for k in range(9):
                if k == i or k == j: continue
                print(a[k])
            exit()