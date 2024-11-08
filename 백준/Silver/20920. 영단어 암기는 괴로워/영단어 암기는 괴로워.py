import sys
input=sys.stdin.readline
n,m=map(int,input().split())

d1=dict()
for _ in range(n):
    name=input().strip()
    if(len(name)>=m):
        if(name in d1):d1[name][0]+=1
        else:d1[name]=[1,len(name),name]

a=sorted(d1.items(), key=lambda x: (-x[1][0],-x[1][1],x[1][2]))
res=[i[0] for i in a]      
print(*res,sep='\n')