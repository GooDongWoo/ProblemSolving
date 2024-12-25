import sys
input = sys.stdin.readline

n, k = map(int, input().split())
a = list(map(int, input().split()))
cnter = 0
for i in range(n // 2):
    max1 = max(a[i], a[n - 1 - i])
    min1 = min(a[i], a[n - 1 - i])
    div = (max1 - min1) // k
    mod = (max1 - min1) % k
    c1 = div + mod
    c2 = (div + 1) + (min1 + ((div + 1) * k) - max1)
    
    cnter += min(c1, c2)

print(cnter)