import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    items=sorted([tuple(map(int,sys.stdin.readline().split())) for _ in range(n)])
    miny=items[0][1]
    cnt=1
    for i in range(1,n):
        if(items[i][1]<miny):
            cnt+=1
            miny=items[i][1]
            if(items[i][1]==1):
                break
    sys.stdout.write(f'{cnt}\n')