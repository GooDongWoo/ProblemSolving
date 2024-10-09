import sys
input=sys.stdin.readline
r,c=map(int,input().split())
l1=[str(i) for i in range(1,10)]
th=[[] for _ in range(c)]
for i in range(r):
    line=input().rstrip()
    for num in l1:
        if(num in line):
            sunsoo=num
            idx=line.index(sunsoo)
            th[idx].append(int(sunsoo))
res=[0]*9
cnt=1
for l in th[::-1]:
    if l:
        for idx in l:
            res[idx-1]=cnt
        cnt+=1
print(*res,sep='\n')