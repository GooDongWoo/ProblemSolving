n=int(input())
res=[]
for _ in range(n):
    j,m=map(int,input().split())
    r=(j-1)%(1+m) #1th
    res.append((2*(j-1-r)//(1+m))+2)
idx=res.index(min(res))
print(idx+1,res[idx])