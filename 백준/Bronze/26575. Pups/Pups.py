n=int(input())
for _ in range(n):
    a,b,c=map(float,input().split())
    print('$',f'{round(a*b*c,2):.2f}',sep='')