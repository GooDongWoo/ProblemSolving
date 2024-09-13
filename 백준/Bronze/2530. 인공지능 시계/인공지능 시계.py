a,b,c=map(int,input().split())
n=int(input())
n+=a*3600 + b*60 +c
h=n//(3600)
m=(n-h*3600)//60
s=(n-h*3600-m*60)

print(h%24,m,s)