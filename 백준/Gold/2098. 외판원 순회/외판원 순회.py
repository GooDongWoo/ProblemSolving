import sys
n=int(sys.stdin.readline())
cost = [list(map(int,input().split())) for _ in range(n)]

def find(visited,now):
    if dp[visited][now]: 
        return dp[visited][now]
    
    if visited == (1<<n) - 1:
        return cost[now][0] if cost[now][0] > 0 else int(1e9)
    tmp = int(1e9)
    for i in range(1,n):
        if (not (visited >> i) % 2) and cost[now][i]:
            tmp = min(tmp, find(visited | (1<<i), i) + cost[now][i])
    dp[visited][now] = tmp
    return tmp
dp = [[0]*n for _ in range(1<<n)]
print(find(1,0))

#BB했는데 왜 시간초과함? 똑같은 지수 시간아님?
'''
import sys
n=int(sys.stdin.readline())
inf=int(1e9)
w=[[inf for _ in range(n)]for _ in range(n)]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    for idx,item in enumerate(tmp):
        if(item==0 and not(idx==i)):
            w[i][idx]=inf
        else:
            w[i][idx]=item

visited=[0]*n
visited[0]=1
min_profit=inf

def bound(start,cur_score):
    global n,w,min_profit,visited
    bound=cur_score
    bound+=min(w[start][1:start]+w[start][start+1:])
    for i in range(1,len(visited)):
        if(visited[i]==0):
            tmp=inf
            for j in range(len(w[i])):
                if(j!=start and j!=i):
                    tmp=min(tmp,w[i][j])
            bound+=tmp
    if(bound<min_profit):
        return True
    else:
        return False

def TSP(start,rad,cur_score):
    global n,w,min_profit,visited
    if(not(cur_score) or bound(start,cur_score)):
        if(rad==(n-1)):
            tmp=cur_score
            for i in range(len(visited)):
                if(visited[i]==0):
                    tmp+=w[start][i]
                    tmp+=w[i][0]
            min_profit=min(min_profit,tmp)
            return
        for idx,weight in enumerate(w[start]):
            if(weight!=0 and weight!=inf and visited[idx]==0):
                visited[idx]=1
                TSP(idx,rad+1,cur_score+weight)
                visited[idx]=0
TSP(0,1,0)
print(min_profit)'''