import sys
input=sys.stdin.readline
MAX=123456*2+1
primes=[True]*MAX
primes[0]=primes[1]=False
for i in range(2,MAX):
    if primes[i]:
        for j in range(i*i,MAX,i):
            primes[j]=False
cnter=[0]*MAX
for i in range(1,MAX):
    cnter[i]=cnter[i-1]+primes[i]

while 1:
    n=int(input())
    if(n==0):break
    print(cnter[2*n]-cnter[n])