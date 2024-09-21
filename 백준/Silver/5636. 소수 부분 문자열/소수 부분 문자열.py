import sys
def sieve():
    lim=100000
    primes=[1]*(lim+1)
    primes[0]=primes[1]=0
    p_list=[]
    for i in range(2,lim+1):
        if(primes[i]):
            p_list.append(i)
            for j in range(i*i,lim+1,i):
                primes[j]=0
    p_list.reverse()
    return p_list
p_list=sieve()

while 1:
    n=sys.stdin.readline().rstrip()
    if(n=='0'): break
    max1=0
    for p in p_list:
        if(str(p) in n):sys.stdout.write(f'{p}\n');break
            