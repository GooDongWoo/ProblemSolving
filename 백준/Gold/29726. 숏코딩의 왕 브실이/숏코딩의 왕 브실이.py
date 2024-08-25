import sys
n,m=map(int,sys.stdin.readline().split())
a=[*map(int,sys.stdin.readline().split())]
mins=[0]*n
maxs=[0]*n
min1=float('inf')
max1=-float('inf')

for i in range(n):
    min1=min(min1,a[i])
    mins[i]=min1
    
for i in range(n-1,-1,-1):
    max1=max(max1,a[i])
    maxs[i]=max1

res=[]
for i in range(m+1):
    res.append(maxs[n-1-m+i]-mins[i])
print(max(res))