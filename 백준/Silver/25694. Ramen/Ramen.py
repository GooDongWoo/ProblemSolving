import sys
input = sys.stdin.readline
n=int(input())
l=list(map(int,input().split()))
if(n==1):
    print("YES")
    exit()
cur=0
for i in range(n-1):
    cur+=l[i]
    if(cur<=0):
        print('NO')
        exit()
print('YES')