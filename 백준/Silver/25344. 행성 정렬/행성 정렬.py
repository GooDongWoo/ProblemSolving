def gcd(a,b):
    t1=max(a,b)
    t2=min(a,b)
    while t2!=0:
        t1,t2=t2,t1%t2
    return t1

n=int(input())
planets=[*map(int,input().split())]
ans=planets[0]
for i in range(len(planets)):
    tmp=gcd(ans,planets[i])
    ans=(ans//tmp)*planets[i]

print(ans)    