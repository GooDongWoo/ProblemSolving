import sys
input = sys.stdin.readline

from collections import deque

def chck(y, x):
    global h, w, mat, kq, keys, v, q, cnter
    v[y][x] = 1
    if (mat[y][x] == '.'):
        q.append((y, x))
    elif (mat[y][x] == '$'): 
        cnter += 1
        q.append((y, x))
    elif (mat[y][x] != '*'):
        if (mat[y][x].isupper()):
            idx = ord(mat[y][x]) - ord('A')
            if (keys[idx]): q.append((y, x))
            else: kq[idx].append((y, x))
        else:
            idx = ord(mat[y][x]) - ord('a')
            if (keys[idx]): q.append((y, x))
            else:
                keys[idx] = 1
                while (kq[idx]): q.append(kq[idx].popleft())
                q.append((y, x))
    

t = int(input())
for _ in range(t):
    h, w = map(int, input().split())
    mat = [list(input().rstrip()) for _ in range(h)]
    kq = [deque() for _ in range(26)]
    keys = [0]*26
    cnter = 0
    tmp = list(input().rstrip())
    if (tmp[0] != '0'):
        for char in tmp: keys[ord(char)-ord('a')] = 1
    
    v = [[0]*w for _ in range(h)]
    q = deque()
    for i in range(h):
        chck(i,0)
        chck(i, w-1)
    for i in range(1, w-1):
        chck(0,i)
        chck(h-1,i)
        
    while (q):
        y, x = q.popleft()
        for dy, dx in [(1,0),(0,1),(-1,0),(0,-1)]:
            ny, nx = y + dy, x + dx
            if (0<=ny<h and 0<=nx<w and v[ny][nx] == 0):
                chck(ny, nx)
    print(cnter)

# 처음에 테두리를 다 둘러보고 갈 수 있는 곳은 전부 큐에 넣기
# 만약 문이라면 열 수 있으면 큐에 넣고 없으면 키큐에 넣기 
# 키라면 해당 키를 1로 만들고 해당 키큐를 전부 팝해서 큐에 넣기
# 그다음 BFS 돌리기(위의 과정을 행동하면서) v 체크하고 
# 문서라면 cnter++하고 주변 탐색 ㄱㄱ