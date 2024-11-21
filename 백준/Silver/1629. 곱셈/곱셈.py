import sys
input=sys.stdin.readline

def prod(a,b,c):
    if(b==1):
        return a%c
    if(b%2==0):
        return ((prod(a,b//2,c)%c)**2)%c
    else:
        return ((((prod(a,b//2,c))**2)%c)*a)%c

a,b,c=map(int,input().split())
print(prod(a,b,c))