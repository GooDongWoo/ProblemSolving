import sys
from collections import deque

test_case=int(sys.stdin.readline())
for _ in range(test_case):
    num1,num2=map(int,sys.stdin.readline().split())
    visited = [False for _ in range(10001)]
    q=deque()
    q.append([num1,""])
    visited[num1]=True
    while q:
        parent_num_oplst=q.popleft()
        
        if parent_num_oplst[0] == num2:
            sys.stdout.write(parent_num_oplst[1]+f'\n')
            break
        
        d = parent_num_oplst[0] * 2 % 10000
        if not visited[d]:
            visited[d] = True
            q.append([d, parent_num_oplst[1] + 'D'])

        s = (parent_num_oplst[0] - 1) % 10000 if parent_num_oplst[0]!=0 else 9999
        if not visited[s]:
            visited[s] = True
            q.append([s, parent_num_oplst[1] + 'S'])

        l = parent_num_oplst[0] // 1000 + (parent_num_oplst[0] % 1000)*10
        if not visited[l]:
            visited[l] = True
            q.append([l, parent_num_oplst[1] + 'L'])

        r = parent_num_oplst[0] // 10 + (parent_num_oplst[0] % 10) * 1000
        if not visited[r]:
            visited[r] = True
            q.append([r, parent_num_oplst[1] + 'R'])