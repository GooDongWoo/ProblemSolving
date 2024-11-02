import sys
input=sys.stdin.readline
MAX=(int(int(5e9)**(0.5))+1)
primes=[True]*MAX
primes[0]=primes[1]=False
for i in range(MAX):
    if(primes[i]):
        for j in range(i**2,MAX,i):
            primes[j]=False

prime_list=[i for i in range(MAX) if primes[i]]
t=int(input())
for _ in range(t):
    n=int(input())
    if(n==1 or n==0):
        print(2)
        continue
    while 1:
        failFlag=False
        for i in prime_list:
            if(i>=(int(n**(0.5))+1)):break
            if(n%i==0):
                failFlag=True
                break
        if not (failFlag):
            print(n)
            break
        n+=1