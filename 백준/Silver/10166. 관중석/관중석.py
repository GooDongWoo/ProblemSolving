def  gcd(a1,a2):
    b=max(a1,a2)
    s=min(a1,a2)
    if(s==0):return -1
    if(b%s==0):return s
    return gcd(s,b%s)

d1,d2=map(int,input().split())
occupied=set()
for nth in range(d1,d2+1):
    for j in range(nth):
        res=gcd(j,nth)
        if(res==-1):
            occupied.add((0,360))
        else:
            occupied.add((j//res,nth//res))
print(len(occupied))