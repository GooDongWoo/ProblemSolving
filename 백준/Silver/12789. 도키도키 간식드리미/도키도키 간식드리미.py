import sys
input=sys.stdin.readline

n=int(input())
l=list(map(int,input().split()))

idx=0
stck=[]
target=1
while idx<n:
    if(l[idx]==target):
        target+=1
        idx+=1
    else:
        if(stck and stck[-1]==target):
            stck.pop()
            target+=1
        else:
            stck.append(l[idx])
            idx+=1

success=False
if not(stck):
    success=True
else:
    if(stck[::-1]==sorted(stck)):
        success=True
res="Nice" if success else "Sad"
print(res)