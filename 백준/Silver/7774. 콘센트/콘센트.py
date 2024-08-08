import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[]
b=[]
if(n):
    a=sorted([*map(int,input().split())],reverse=True)
if(m):
    b=sorted([*map(int,input().split())],reverse=True)

def sol():
    global n,m,a,b
    if(n==0):
        print(1)
        return
    if(m==0):
        print(1)
        return
    adx=0
    bdx=0
    flag=1
    ca=1
    cb=0
    while flag:
        ca-=1
        cb+=a[adx]
        adx+=1
        while cb!=0 and bdx<len(b):
            cb-=1
            ca+=b[bdx]
            bdx+=1
        flag=(ca>0) and (adx<len(a)) and (bdx<len(b))
    print(ca)

sol()