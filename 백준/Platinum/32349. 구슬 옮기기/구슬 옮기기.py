import sys
input=sys.stdin.readline
w,h=map(int,input().split())
bef=[list(map(int,input().split())) for _ in range(h)]
aft=[list(map(int,input().split())) for _ in range(h)]
aft_cnt=0
bef_cnt=0
starts=[]
ends=[]
for i in range(h):
    for j in range(w):
        if(bef[i][j]==aft[i][j]):
            bef[i][j]=aft[i][j]=0
        if(bef[i][j]==1):
            bef_cnt+=1
            starts.append((i,j))
        if(aft[i][j]==1):
            aft_cnt+=1
            ends.append((i,j))
if(aft_cnt!=bef_cnt):
    print(-1)
    exit()

adj_v=[[] for _ in range(len(starts))]
for i in range(len(starts)):
    sy,sx=starts[i]
    for j in range(len(ends)):
        ey,ex=ends[j]
        if(abs(sy-ey)+abs(sx-ex)==1):
            adj_v[i].append(j)

matched_Y=[-1]*(len(ends))
matched_X=[-1]*(len(starts))
def dfs(x):
    visited[x] = True
    for y in adj_v[x]:
        if matched_Y[y] == -1:
            matched_Y[y] = x
            matched_X[x] = y
            return True
        elif not visited[matched_Y[y]] and dfs(matched_Y[y]):
            matched_Y[y] = x
            matched_X[x] = y
            return True
    return False

cnt = 0
for i in range(len(starts)):
    visited = [False] * (len(starts))
    if dfs(i):
        cnt += 1
print(2*(len(starts)-cnt) + cnt)