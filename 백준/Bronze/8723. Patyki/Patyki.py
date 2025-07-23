a,b,c = sorted(map(int,input().split()))
if(a**2 + b**2 == c**2):
    print(1)
elif (a==b==c):
    print(2)
else:
    print(0)