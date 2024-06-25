import sys
from collections import deque
import heapq
inf=int(1e8)
n,m,k=map(int,sys.stdin.readline().split())
c_list=list(map(int,sys.stdin.readline().split()))
f_list=[[] for _ in range(n+1)]
for _ in range(m):
    f1,f2=map(int,sys.stdin.readline().split())
    f_list[f1].append(f2)
    f_list[f2].append(f1)
visited=[0]*(n+1)
def dfs(start):
    global n,m,k,c_list,f_list,visited
    if(visited[start]!=0):
        return 0
    stck=deque()
    stck.append(start)
    c_cnt=0
    f_cnt=0
    while stck:
        parent=stck.pop()
        if(visited[parent]==0):
            visited[parent]=1
            c_cnt+=c_list[parent-1]
            f_cnt+=1
            for child in f_list[parent]:
                if(visited[child]==0):
                    stck.append(child)
    return (f_cnt,c_cnt)
knap_t_list=[]
for i in range(1,n+1):
    tmp=dfs(i)
    if(tmp):
        knap_t_list.append((i,tmp)) #root,cnt
for i in range(len(knap_t_list)):
    knap_t_list[i]=knap_t_list[i][1]
knap_t_list.sort(key=lambda x:x[1],reverse=True)#가격 내림차순
knap_t_list.sort(key=lambda x:x[0])#무게 오름차순

dp_list=[[0]*(k) for _ in range(len(knap_t_list)+1)]
for i in range(1,len(knap_t_list)+1):
    for j in range(1,k):
        if j-knap_t_list[i-1][0]>=0:
            dp_list[i][j]=max(dp_list[i-1][j],dp_list[i-1][j-knap_t_list[i-1][0]]+knap_t_list[i-1][1])
        else:
            dp_list[i][j]=dp_list[i-1][j]
print(dp_list[len(knap_t_list)][k-1])