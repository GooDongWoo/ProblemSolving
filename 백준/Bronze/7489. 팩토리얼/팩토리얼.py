t=int(input())
for _ in range(t):
    n=int(input())
    result=1
    for i in range(2,n+1):
        result*=i
        while (result%10==0): result//=10
    print(str(result)[-1])