def sieve(lim):
    p=[]
    tot=[1]*(lim+1)
    tot[0]=0
    tot[1]=0
    for i in range(2,lim+1):
        if tot[i]==1:
            p.append(i)
            for j in range(i*i,lim+1,i):
                tot[j]=0
    return p
import sys
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
accum_a=[0]*(n+1)
accum_a[1]=a[0]
for i in range(1,n):
    accum_a[i+1]=accum_a[i]+a[i]
ps=sieve(500*2000)
ps_set=set(ps)
cnt=0
for p in ps:
    if(p>n):break
    for i in range(p,n+1):
        candidate=accum_a[i]-accum_a[i-p]
        if candidate in ps_set:
            cnt+=1
print(cnt)