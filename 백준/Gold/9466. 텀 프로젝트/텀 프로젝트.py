import sys
from collections import deque
input = sys.stdin.readline

def bfs(start):
    if picks[start] == start:  # 자기 자신을 선택하는 경우
        cycles[start] = 1
        return
    q = deque([start])
    path = []  # 현재 경로를 저장
    while q:
        current = q.popleft()
        if cycles[current] != 0:  # 이미 처리된 노드라면 종료
            break
        if visited[current]:  # 이미 방문한 노드를 다시 방문한 경우
            if current in path:
                cycle_start = path.index(current)
                for node in path[cycle_start:]:  # 사이클에 속하는 노드만 처리
                    cycles[node] = 1
            return
        visited[current] = 1
        path.append(current)
        q.append(picks[current])  # 다음 노드로 이동

    # 사이클에 포함되지 않은 노드는 -1로 처리
    for node in path:
        if cycles[node] == 0:
            cycles[node] = -1

t = int(input())
for _ in range(t):
    n = int(input())
    picks = list(map(lambda x: int(x) - 1, input().split()))  # 0-index로 변환
    cycles = [0] * n  # 노드의 상태를 저장: 0 = 미처리, 1 = 사이클, -1 = 비사이클
    visited = [0] * n  # 방문 여부를 저장

    for i in range(n):
        if cycles[i] == 0:  # 미처리 노드만 탐색
            bfs(i)

    # 사이클에 포함되지 않은 노드 개수 계산
    non_cycle_count = sum(1 for x in cycles if x != 1)
    sys.stdout.write(f'{non_cycle_count}\n')
