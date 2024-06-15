from collections import deque
import sys
input= sys.stdin.readline
print=sys.stdout.write

def dfs(n, adj_m, chck_bef):
    tmp=deque()
    chck_bef[n]=1
    for i in range(len(adj_m[n])):
        if chck_bef[adj_m[n][i]]==0:
            tmp.append(adj_m[n][i])
            chck_bef[adj_m[n][i]]=1
        else:
            pass
    if tmp:
        dfs(tmp.pop(), adj_m, chck_bef)
    else:
        return

#input
n_node, n_edge=map(int,input().split())

#initialize
chck_bef=[0]*(n_node+1)
adj_m=[[] for _ in range(n_node+1)]
cnt=0

#edge input
for _ in range(n_edge):
    n1, n2=map(int,input().split())
    adj_m[n1].append(n2)
    adj_m[n2].append(n1)

#using deque DFS 
for i in range(1,n_node+1):
    if chck_bef[i]==0:
        cnt+=1
        dfs(i,adj_m, chck_bef)

print(f'{cnt}')