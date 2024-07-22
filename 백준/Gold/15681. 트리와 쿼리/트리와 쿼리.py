import sys
sys.setrecursionlimit(int(1e9))
n,r,q=map(int,sys.stdin.readline().split())
connect=[[] for _ in range(n+1)]
for _ in range(n-1):
    a,b=map(int,sys.stdin.readline().split())
    connect[a].append(b)
    connect[b].append(a)

def countSubtreeNodes(currentNode,parent):
    global size
    size[currentNode] = 1 
    for Node in connect[currentNode]:
        if(Node!=parent):
            countSubtreeNodes(Node,currentNode)
            size[currentNode] += size[Node]

size=[0]*(n+1)
countSubtreeNodes(r,-1)
for _ in range(q):
    t=int(sys.stdin.readline())
    sys.stdout.write(f'{size[t]}\n')