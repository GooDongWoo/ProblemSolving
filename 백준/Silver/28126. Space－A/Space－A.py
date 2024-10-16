import sys
sys.setrecursionlimit(int(5e5))
input=sys.stdin.readline

n=int(input())
cnter=[0]*3
a=input().rstrip()
for i in a:
    if(i=='R'):cnter[0]+=1
    elif(i=='U'):cnter[1]+=1
    else:cnter[2]+=1
    
k=int(input())
cnt=0
for _ in range(k):
    x,y=map(lambda x:int(x)-1,input().split())
    min1=min(cnter[2],x,y)
    nx,ny=x-min1,y-min1
    if(nx<=cnter[0] and ny<=cnter[1]):cnt+=1
print(cnt)