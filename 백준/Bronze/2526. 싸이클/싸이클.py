n,p=map(int,input().split())
l=[0]*100
tmp=n%p
l[n%p]=1
idx=2
while 1:
    tmp=tmp*n%p
    if(l[tmp]):
        print(idx-l[tmp])
        break
    l[tmp]=idx
    idx+=1