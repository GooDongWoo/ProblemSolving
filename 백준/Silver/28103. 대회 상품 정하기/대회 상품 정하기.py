import sys
input = sys.stdin.readline

n, m, x = map(int, input().split())
a = [*map(int, input().split())]
cnters = [0] * m
left_p = n
left_m = x
for i in range(m-1):
    if (left_m - (a[-1] * left_p)) <= 0:continue
    p = (left_m - (a[-1] * left_p)) // (a[i] - a[-1])
    if p > left_p:
        cnters[i] = left_p
        break
    left_p -= p
    left_m -= a[i] *p
    
    cnters[i] = p

cnters[-1] = n - sum(cnters)
print(*cnters)