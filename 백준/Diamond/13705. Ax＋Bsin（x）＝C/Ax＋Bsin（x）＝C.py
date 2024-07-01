from decimal import Decimal,getcontext
getcontext().prec=50
a,b,c=map(Decimal,(map(int,input().split())))
PI=Decimal('3.14159265358979323846')
n=100
def sin(x):
    x-=(c/a//(PI*2))*(2*PI)
    res=Decimal(0)
    term=x
    x_squared=x*x
    for k in range(n+1):
        res+=term
        term*=-x_squared/((2*k+2)*(2*k+3))
    return res
def cos(x):
    x-=(c/a//(PI*2))*(2*PI)
    res=Decimal(1)
    term=Decimal(1)
    x_squared=x*x
    for k in range(1,n+1):
        term*=-x_squared/((2*k-1)*(2*k))
        res+=term
    return res
def cal1(x):
    return a*x+b*sin(x)-c
def cal2(x):
    return a+b*cos(x)
x=c/a
for i in range(1000):
    if abs(cal1(x))<Decimal('1e-25'):
        break
    x-=cal1(x)/cal2(x)
print(round(x,6))