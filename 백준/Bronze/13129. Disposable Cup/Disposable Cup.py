a,b,n=map(int,input().split())
l1=[(a+b)*(n-i)+a*(i) for i in range(n-1,-1,-1)]
print(*l1)