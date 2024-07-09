d1,d2,d3=map(int,input().split())

s=(d1+d2+d3)/2
a=s-d3
b=s-d2
c=s-d1
if(a<=0 or b<=0 or c<=0):
    print(-1)
else:
    print(1)
    print(f'{a:.1f} {b:.1f} {c:.1f}')