from collections import deque
import sys

def bfs(n, k):
    if n == k:
        return 0
    incre = 1
    q = deque([n])
    visited = [[False] * 500001 for _ in range(2)]
    while q:
        k += incre
        if k > 500000:
            return -1
        if visited[incre % 2][k]:
            return incre
        siz = len(q)
        for _ in range(siz):
            x = q.popleft()
            for nx in (x - 1, x + 1, 2 * x):
                if nx == k:
                    return incre
                if (0<=nx<=500000) and not (visited[incre % 2][nx]):
                    visited[incre % 2][nx] = True
                    q.append(nx)
        incre += 1
    return -1
n, k = map(int, sys.stdin.readline().split())
result = bfs(n, k)
print(result)