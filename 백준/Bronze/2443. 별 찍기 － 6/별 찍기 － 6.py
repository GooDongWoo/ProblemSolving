n=int(input())
space=' '
star='*'
for i in range(1,n+1):
    print((space*(i-1))+(star*(2*n-(2*i-1))))