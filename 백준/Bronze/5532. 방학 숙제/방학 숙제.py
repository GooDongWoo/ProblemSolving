import sys
input=sys.stdin.readline

n=int(input())
a=int(input())
b=int(input())
c=int(input())
d=int(input())

d1=a//c if a%c==0 else a//c +1
d2=b//d if b%d==0 else b//d +1
print(n-max(d1,d2))