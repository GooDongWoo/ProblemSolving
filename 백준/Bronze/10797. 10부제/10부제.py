n=int(input())
l=list(map(lambda x: int(x[-1]),input().split()))
cnt=0
for i in l:
    if(n==i):
        cnt+=1
print(cnt)