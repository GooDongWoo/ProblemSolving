n=int(input())
a=[*map(int,input().split())]
#chcker=[[] for _ in range(n)]
cnter=[1]*n
for i in range(1,n):
    for j in range(i-1,-1,-1):
        if a[i]>a[j] :#and not(a[j] in chcker[i])
            #chcker[i].append(a[j])
            cnter[i]+=(cnter[j])
        cnter[i]%=998244353

print(*cnter)