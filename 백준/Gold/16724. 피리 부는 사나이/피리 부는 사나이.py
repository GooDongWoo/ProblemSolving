class Node():
    def __init__(self,dir) -> None:
        self.val=dir
        self.parent=None
        self.children=[]
        self.size=1

def find(n1:Node)->Node:
    p_node=n1
    while p_node.parent!=None:
        p_node=p_node.parent
    return p_node

def union(n1:Node,n2:Node)-> None:
    root_1=find(n1)
    root_2=find(n2)
    if(root_1.size>root_2.size):
        root_2.parent=root_1
        root_1.children.append(root_2)
        root_1.size+=root_2.size
    else:
        root_1.parent=root_2
        root_2.children.append(root_1)
        root_2.size+=root_1.size

import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
optr_mat=[0]*n
for i in range(n):
    optr_mat[i]=list(sys.stdin.readline().rstrip())
    
nodes=[[Node((i,j)) for j in range(m)] for i in range(n)]
optr_dict={'D':(1,0),'U':(-1,0),'L':(0,-1),'R':(0,1)}

def dfs(start):
    global nodes,optr_mat,n,m
    if (find(start)!=start):
        return
    stck=deque()
    stck.append(start)
    while stck:
        child=stck.pop()
        dy,dx=optr_dict[optr_mat[child.val[0]][child.val[1]]]
        if(find(child)!=find(nodes[child.val[0]+dy][child.val[1]+dx])):
            union(nodes[child.val[0]+dy][child.val[1]+dx],child)
            stck.append(nodes[child.val[0]+dy][child.val[1]+dx])
for i in range(n):
    for j in range(m):
        dfs(nodes[i][j])
root_set=set()
for i in range(n):
    for j in range(m):
        root_set.add(find(nodes[i][j]))
print(len(root_set))