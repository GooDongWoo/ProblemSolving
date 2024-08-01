def F(a):
    global n
    cost =0
    i = 0
    while i < n:
        if i <= n - 3 and a[i+1] > a[i+2]:
            m = min(a[i], a[i+1] - a[i+2])
            cost += 5 * m;a[i] -= m;a[i+1] -= m
        if i <= n - 3:
            m = min(a[i], a[i+1], a[i+2])
            cost += 7 * m
            a[i] -= m;a[i+1] -= m;a[i+2] -= m
        elif i <= n - 2:
            m = min(a[i], a[i+1])
            cost += 5 * m
            a[i] -= m;a[i+1] -= m
        if a[i] > 0:
            cost += 3 * a[i]
            a[i] = 0
        i += 1

    return cost

n = int(input())
a = list(map(int, input().split()))
print(F(a))