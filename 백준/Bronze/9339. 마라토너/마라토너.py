import sys
t=int(sys.stdin.readline())
for _ in range(t):
    k=int(sys.stdin.readline())
    cs=set([*map(int,sys.stdin.readline().split())])
    n=int(sys.stdin.readline())
    result=[]
    for _ in range(n):
        num,h,m=map(int,sys.stdin.readline().split())
        if(num in cs) and (h!=-1 and (h<6 or (h==6 and m==0))):
            result.append((num,h,m))
    result.sort(key=lambda x:(x[1],x[2]))
    sys.stdout.write(f'{result[0][0]} {len(result)}\n')