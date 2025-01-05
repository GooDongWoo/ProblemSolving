import sys
input=sys.stdin.readline
import heapq

n, m = map(int, input().split())
cnters = [0] * n
adj_v = [[] for _ in range(n)]
H = []
for _ in range(m):
    a, b = map(lambda x: int(x) - 1, input().split())
    adj_v[a].append(b)
    cnters[b] += 1

for i in range(n):
    if cnters[i] == 0:
        heapq.heappush(H, i)

ans = []
while H:
    pop1 = heapq.heappop(H)
    ans.append(pop1 + 1)
    for i in adj_v[pop1]:
        cnters[i] -= 1
        if cnters[i] == 0:
            heapq.heappush(H, i)

print(*ans)