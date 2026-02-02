import sys
input = sys.stdin.readline

N = int(input())
ans = N

for i in range(2, int(N ** .5) + 1):
    if not (N % i):
        while (not (N % i)):
            N //= i
        ans *= (1 - (1 / i))

if N > 1:
    ans *= (1 - (1 / N))

print(int(ans))