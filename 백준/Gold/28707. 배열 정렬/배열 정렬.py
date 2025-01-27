import sys
input = sys.stdin.readline

import heapq

INF = int(1e9)
n = int(input())
l = [*map(lambda x: str(int(x)-1),input().split())]
q = int(input())
qs = []
for _ in range(q):
    s, e, w = map(int, input().split())
    s -= 1; e -= 1
    qs.append((s, e, w))

d = dict()
mh = [(0, ''.join(l))]
while (mh):
    dist, cur = heapq.heappop(mh)
    if (cur in d):continue
    d[cur] = dist
    for i in range(q):
        tmp = list(cur)
        tmp[qs[i][0]], tmp[qs[i][1]] = tmp[qs[i][1]], tmp[qs[i][0]]
        new = ''.join(tmp)
        if (new in d):continue
        heapq.heappush(mh, (dist + qs[i][2], new))

ans = ''.join(sorted(l))
if (ans in d): print(d[ans])
else: print(-1)