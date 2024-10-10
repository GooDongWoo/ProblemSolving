import sys
input=sys.stdin.readline
n,k,x=map(int,input().split())
l=sorted([tuple(map(int,input().split())) for _ in range(n)])
start=0
end=l[-1][0]
while start<=end:
    mid=(start+end)//2
    subl=sorted([(i[0]-mid)*i[1] if i[0]-mid >0 else 0 for i in l ])
    target=sum(subl[:-x+1]) if x!=1 else sum(subl)
    
    if(target<k):
        end=mid-1
    else:
        start=mid+1

print(start)