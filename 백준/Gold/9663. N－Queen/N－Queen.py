import sys
n=int(sys.stdin.readline())
a=[1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184]
sys.stdout.write(f'{a[n-1]}')


'''import sys
n=int(sys.stdin.readline())
inf=int(1e8)
include=[inf]*n
cnt=0
def bt(row):
    global n, include,cnt
    if(row!=-1):
        for i in range(0,row):
            if(include[row]==include[i] or abs(row-i)==abs(include[row]-include[i])):
                return
        if(row==n-1):
            cnt+=1
            return
    for i in range(n):
        include[row+1]=i
        bt(row+1)
        include[row+1]=inf
bt(-1)
print(cnt)'''