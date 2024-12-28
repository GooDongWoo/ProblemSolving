import sys
input=sys.stdin.readline

n, a, b = map(int, input().split())
points = [list(map(int, input().split())) for _ in range(n)]
ans = 0
for i in range(n-1):
    for j in range(i+1, n):
        r1, c1, v1 = points[i]
        r2, c2, v2 = points[j]
        if abs(r1 - r2) < a and abs(c1 - c2) < b:
            ans = max(ans, abs(v1 - v2))
print(ans)