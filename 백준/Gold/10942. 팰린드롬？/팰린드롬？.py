import sys
def oddChck(mid):
    global dp_mat
    i=1
    while (mid-i>-1 and mid+i<n):
        if(item_list[mid-i]==item_list[mid+i]):
            dp_mat[mid+i][mid-i]=1
        else:
            break
        i+=1
        
def evenChck(right):
    global dp_mat
    i=1
    while (right-i>-1 and right-1+i<n):
        if(item_list[right-i]==item_list[right-1+i]):
            dp_mat[right-1+i][right-i]=1
        else:
            break
        i+=1

inf=int(1e8)
n=int(sys.stdin.readline())
item_list=list(map(int,sys.stdin.readline().split()))
dp_mat=[[0 for _ in range(row)] for row in range(1,n+1)]
for row in range(n):
    dp_mat[row][row]=1

for idx in range(1,len(dp_mat)):
    evenChck(idx)
    oddChck(idx)

m=int(sys.stdin.readline())
for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    if(dp_mat[end-1][start-1]):
        sys.stdout.write(f'1\n')
    else:
        sys.stdout.write(f'0\n')        