t=int(input())
for _ in range(t):
    n,x,y=map(int,input().split())
    vs=list(map(int,input().split()))
    max1=0
    for i in range(n-1):
        max1=max(max1,vs[i])
    time_limit=x/max1
    s=vs[-1]
    #case1, 항상 우승
    if(s>max1):
        print(0)
    #case2, 우승 ㄴㄴ
    elif((x-y)>=(time_limit-1)*s):
        print(-1)
    #case3, 직접 구해야함
    else:
        print(int((x-(time_limit-1)*s))+1)
