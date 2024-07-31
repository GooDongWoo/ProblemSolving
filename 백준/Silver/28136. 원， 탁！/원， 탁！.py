import sys
n=int(sys.stdin.readline())
a=[*map(int,sys.stdin.readline().split())]
a.append(a[0])
cnt=0
for i in range(1,len(a)):
    if(a[i-1]>=a[i]):
        cnt+=1
print(cnt)