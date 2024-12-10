import sys
input = sys.stdin.readline


n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]
b = [int(input()) for _ in range(m)]

selected = [0] * n
for i in range(m):
    target = b[i]
    for j in range(n):
        if target >= a[j]:
            selected[j] += 1
            break

print(selected.index(max(selected)) + 1)