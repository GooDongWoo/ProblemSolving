a,b=map(int,input().split())
q=list(map(int,input().split()))
tot=a*b
for i in q:
    print(i-tot,end=' ')