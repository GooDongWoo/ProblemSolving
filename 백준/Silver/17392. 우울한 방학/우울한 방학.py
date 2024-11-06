import sys
input=sys.stdin.readline

n,m=map(int,input().split())
l=[*map(lambda x:int(x)+1,input().split())]
possible=len(l)+1
h_days=sum(l)

left=m-h_days
if(left<=0):
    print(0)
    exit()

div,mod=left//possible,left%possible
anss=[div for _ in range(possible)]
for i in range(mod):
    anss[i]+=1
res=sum([(i)*(i+1)*(2*i+1)//6 for i in anss])
print(res)