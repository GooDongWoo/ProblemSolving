import sys
input=sys.stdin.readline
r,c=map(int,input().split())
k=int(input())
rs=[0]
cs=[0]
for _ in range(k):
    a,b=map(int,input().split())
    if(a):cs.append(b)
    else:rs.append(b)

cs.append(r)
rs.append(c)

rs.sort()
cs.sort()

res=[]
rl=len(rs)
cl=len(cs)
for i in range(1,rl):
    w=rs[i]-rs[i-1]
    for j in range(1,cl):
        h=cs[j]-cs[j-1]
        res.append(w*h)

print(max(res))