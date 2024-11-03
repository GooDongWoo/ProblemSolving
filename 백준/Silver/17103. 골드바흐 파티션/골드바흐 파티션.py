import sys
input=sys.stdin.readline
MAX=int(1e6)+1
primes=[True]*MAX
primes[0]=primes[1]=False
primelist=[]
for i in range(2,MAX):
    if primes[i]:
        primelist.append(i)
        for j in range(i*i,MAX,i):
            primes[j]=False

res=[]
t=int(input())
for _ in range(t):
    n=int(input())
    cnt=0
    for prime in primelist:
        if(prime>n//2):break
        if(primes[n-prime]==True):cnt+=1
    res.append(cnt)
print('\n'.join(map(str,res)))