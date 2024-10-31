import sys
input=sys.stdin.readline
n,k=map(int,input().split())
l=list(map(int,input().split()))
cnt=0
for i in range(1,n):
    if(l[i]-l[i-1]>k):
        cnt+=i*((l[i]-l[i-1])-k)
    elif(l[i]-l[i-1]<k):
        cnt+=k-(l[i]-l[i-1])
        l[i]=l[i-1]+k
    else:
        pass
print(cnt)