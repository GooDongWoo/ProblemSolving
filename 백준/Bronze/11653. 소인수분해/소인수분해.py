import sys
input=sys.stdin.readline

n=int(input())

primes=[]
sieves=[True]*(n+1)
sieves[0]=sieves[1]=False
for i in range(2, n+1):
    if sieves[i]:
        primes.append(i)
        for j in range(i*i, n+1, i):
            sieves[j]=False

if n==1:
    exit(0)
else:
    while n>1:
        for p in primes:
            if n%p==0:
                print(p)
                n//=p
                break