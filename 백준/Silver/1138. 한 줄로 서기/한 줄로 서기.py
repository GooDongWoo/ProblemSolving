n=int(input())
tallerthme=[*map(int,input().split())]
result=[0]*n
leftdir=[i for i in range(n)]

for i in range(n):
    cnt=0
    idx=0
    while cnt!=tallerthme[i] or result[idx]!=0:
        if(result[idx]==0):
            cnt+=1
        idx+=1
    result[idx]=i+1
print(*result)