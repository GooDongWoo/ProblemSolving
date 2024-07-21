import sys
n,m=map(int,sys.stdin.readline().split())
res=[0]*m
def bt(idx):
    if(idx==m-1):
        sys.stdout.write(f'{" ".join([*map(str,res)])}\n')
    else:
        for i in range(1,n+1):
            res[idx+1]=i
            bt(idx+1)
bt(-1)