import sys
from collections import deque
input=sys.stdin.readline

n, m = map(int, input().split())
adj_v = [[] for _ in range(n)]
in_cnter = [0] * n
for _ in range(m):
    seq = list(map(lambda x: int(x) - 1, input().split()))
    for i in range(1, len(seq) - 1):
        adj_v[seq[i]].append(seq[i + 1])
        in_cnter[seq[i + 1]] += 1

q = deque()

for i in range(n):
    if in_cnter[i] == 0:
        q.append(i)

ans = []
while q:
    cur = q.popleft()
    ans.append(cur + 1)
    
    for i in adj_v[cur]:
        in_cnter[i] -= 1
        if in_cnter[i] == 0:
            q.append(i)

if sum(in_cnter) != 0:print(0)
else:print(*ans, sep = '\n')