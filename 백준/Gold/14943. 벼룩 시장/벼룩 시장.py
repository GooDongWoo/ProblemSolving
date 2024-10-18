import sys
input = sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
pl=[]
ml=[]
for i in range(n):
    if a[i]>0:pl.append((i,a[i]))
    else:ml.append((i,a[i]))

pi=0
mi=0
ans=0
while pi<len(pl) and mi<len(ml):
    if pl[pi][1]>-ml[mi][1]:
        pl[pi]=(pl[pi][0],pl[pi][1]+ml[mi][1])
        ans+=-ml[mi][1]*abs(pl[pi][0]-ml[mi][0])
        mi+=1
    elif pl[pi][1]<-ml[mi][1]:
        ml[mi]=(ml[mi][0],pl[pi][1]+ml[mi][1])
        ans+=pl[pi][1]*abs(pl[pi][0]-ml[mi][0])
        pi+=1
    else:
        ans+=pl[pi][1]*abs(pl[pi][0]-ml[mi][0])
        pi+=1
        mi+=1
print(ans)