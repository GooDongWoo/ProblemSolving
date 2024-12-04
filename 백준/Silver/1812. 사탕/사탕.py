import sys
input = sys.stdin.readline

n = int(input())
l = [int(input()) for _ in range(n)]
ans = [0] * n
tmp = 0
for i in range(n):
    if i % 2 == 0:
        tmp += l[i]
    else:
        tmp -= l[i]
ans[0] = tmp // 2
for i in range(1, n):
    ans[i] = l[i - 1] - ans[i - 1]
print(*ans, sep='\n')