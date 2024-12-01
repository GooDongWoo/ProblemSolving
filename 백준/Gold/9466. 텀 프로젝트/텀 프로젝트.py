import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    if picks[start] == start:
        cycles[start] = 1
        return
    q = deque([start])
    path = []
    while q:
        current = q.popleft()
        if cycles[current] != 0:
            break
        if visited[current]:
            if current in path:
                cycle_start = path.index(current)
                for node in path[cycle_start:]:
                    cycles[node] = 1
            return
        visited[current] = 1
        path.append(current)
        q.append(picks[current])

    for node in path:
        if cycles[node] == 0:
            cycles[node] = -1

t = int(input())
for _ in range(t):
    n = int(input())
    picks = list(map(lambda x: int(x) - 1, input().split()))  
    cycles = [0] * n  
    visited = [0] * n  

    for i in range(n):
        if cycles[i] == 0:
            bfs(i)

    non_cycle_count = sum(1 for x in cycles if x != 1)
    sys.stdout.write(f'{non_cycle_count}\n')
