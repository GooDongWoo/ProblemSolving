import sys
def f(n, i):
    x = 0
    j = 1
    t = 0
    while j <= n:
        k = (n // j) % 10
        if i < k:
            x += j
        elif i == k:
            x += n % j + 1
        x += k * t * (j // 10)
        j *= 10
        t += 1
    return x
L,U = map(int,sys.stdin.readline().split())
s = 0
for i in range(1, 10):
    s += (f(U, i) - f(L, i)) * i
while L:
    s += L % 10
    L //= 10
sys.stdout.write(f'{s}')
