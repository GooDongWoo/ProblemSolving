n=int(input())
l=[*map(int,input().split())]
v=[0]*n
v[n-1]=1
for i in range(n-2,-1,-1):
    v[i]=min(v[i+1]+1,l[i])

print(sum(v))