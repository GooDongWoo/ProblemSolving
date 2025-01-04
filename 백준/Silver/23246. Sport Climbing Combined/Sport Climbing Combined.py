import sys
input = sys.stdin.readline

n = int(input())
l = []
for _ in range(n):
    b, p, q, r = map(int, input().split())
    l.append((p * q * r, p + q + r, b))
l.sort()
ans = [i[2] for i in l[:3]]
print(*ans)
