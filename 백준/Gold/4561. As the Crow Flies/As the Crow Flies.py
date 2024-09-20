import sys
sys.setrecursionlimit(10**7)
import math
t=int(input())
def dfs(node_num,cw):
        global adj_m,max_w,last_node,visited
        if(cw>max_w):
            max_w=cw
            last_node=node_num
        visited[node_num]=1
        for child_num,w in adj_m[node_num]:
            if(w!=0):
                if(visited[child_num]==0):
                    dfs(child_num,cw+w)
        visited[node_num]=0
        
def ldist(name1,name2):
    x1,y1,z1=d1[name1]
    x2,y2,z2=d1[name2]
    return ((x1-x2)**2 +(y1-y2)**2 +(z1-z2)**2)**(0.5)

def rdist(name1,name2):
    c=ldist(name1,name2)
    return math.acos((2-(c**2))/(2))
    
for _ in range(t):
    n,m=map(int,input().split())
    d1=dict()
    d2=dict()
    d3=dict()
    inf=int(1e8)
    adj_m=[[] for _ in range(n)]

    for i in range(n):
        name, theta,ns,phi,ew=input().split()
        
        if ns=='S': theta=(90+int(theta))/180 *math.pi
        else: theta=(90-int(theta))/180 *math.pi
        
        if(ew=='W'): phi=(180-int(phi))/180 *math.pi
        else: phi=(180+int(phi))/180 *math.pi
        z=math.cos(theta)
        y=math.sin(theta)*math.sin(phi)
        x=math.sin(theta)*math.cos(phi)
        
        d1[name]=(x,y,z)
        d2[name]=i
        d3[i]=name

    for _ in range(n-1):
        start,end=input().split()
        tmp=rdist(start,end)
        adj_m[d2[start]].append((d2[end],tmp))
        adj_m[d2[end]].append((d2[start],tmp))

    visited=[0 for _ in range(n)]
    max_w=0
    last_node=-1
    dfs(0,0)
    start1=last_node
    
    visited=[0 for _ in range(n)]
    max_w=0
    dfs(last_node,0)
    end1=last_node
    nodes_name=sorted([d3[start1],d3[end1]])
    print(*nodes_name)