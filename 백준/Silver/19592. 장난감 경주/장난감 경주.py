import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n,x,y=map(int,sys.stdin.readline().split())
    vs=list(map(int,sys.stdin.readline().split()))
    max1=0
    for i in range(n-1):
        max1=max(max1,vs[i])
    time_limit=x/max1
    s=vs[-1]
    #case1, 항상 우승
    if(s>max1):
        sys.stdout.write(f'0\n')
    #case2, 우승 ㄴㄴ
    elif((x-y)>=(time_limit-1)*s):
        sys.stdout.write(f'-1\n')
    #case3, 직접 구해야함
    else:
        sys.stdout.write(f'{int((x-(time_limit-1)*s))+1}\n')
