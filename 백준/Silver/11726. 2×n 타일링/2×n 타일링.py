import sys
tlist=[0]*1001
tlist[1]=1
tlist[2]=2
for item in range(3,1001):
    tlist[item]=tlist[item-1]+tlist[item-2]
n=int(input())    
print(tlist[n]%10007)