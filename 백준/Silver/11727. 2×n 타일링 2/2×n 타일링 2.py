n=int(input())
tlist=[0]*1001
tlist[1]=1
tlist[2]=3
for item in range(3,n+1):
    tlist[item]=tlist[item-1]+(2*tlist[item-2])
print(tlist[n]%10007)