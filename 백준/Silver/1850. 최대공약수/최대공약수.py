def gcd(a,b):
    max1=max(a,b)
    min1=min(a,b)
    if(max1%min1==0): return min1
    else: return gcd(min1,max1%min1)

a,b=map(int,input().split())
res=gcd(a,b)
print('1'*res)