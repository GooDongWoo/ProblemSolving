import sys
n=int(sys.stdin.readline())
Node=[[] for _ in range(n)]# tree

p=[*map(int,sys.stdin.readline().split())]# node's parent p[i] mean ith node's parent
for i in range(n):
    if(p[i]!=-1):
        Node[p[i]].append(i)
    else:
        root=i

cnter=0
def dfs(start):
    global n,Node,p,cnter
    if(Node[start]==[]):
        cnter+=1
    else:
        for c in Node[start]:
            dfs(c)

t=int(sys.stdin.readline())
if(root!=t):
    Node[p[t]].remove(t)
    dfs(root)
    print(cnter)
else:
    print(0)