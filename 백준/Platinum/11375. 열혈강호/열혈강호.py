import sys
input=sys.stdin.readline
n,m=map(int,input().split())
adj_v=[[] for _ in range(n)]
for i in range(n):
    l=[*map(lambda x:int(x)-1,input().split())]
    adj_v[i]=l[1:]

matched_X=[-1]*(n)
matched_Y=[-1]*(m)
def dfs(x):
    v[x] = True
    for y in adj_v[x]:
        if matched_Y[y] == -1:
            matched_Y[y] = x
            matched_X[x] = y
            return True
        elif not v[matched_Y[y]] and dfs(matched_Y[y]):
            matched_Y[y] = x
            matched_X[x] = y
            return True
    return False

cnt = 0
for i in range(n):
    v = [False]*n
    if dfs(i):
        cnt+=1
print(cnt)