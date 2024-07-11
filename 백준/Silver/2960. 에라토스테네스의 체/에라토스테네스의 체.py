n,k=map(int,input().split())
def solve(n,k):
    v=[1]*(n+1)
    v[0]=v[1]=0
    cnt=0
    for i in range(2,n+1):
        if(v[i]):
            cnt+=1
            if(cnt==k):
                print(i)
                return
            mul=2
            while mul*i<=n:
                if(v[mul*i]):
                    cnt+=1
                    if(cnt==k):
                        print(mul*i)
                        return
                    v[mul*i]=0
                mul+=1
solve(n,k)