import sys
n=int(sys.stdin.readline())
n_list=list(map(int,sys.stdin.readline().split()))

sieve=[i for i in range(5000001)]
for i in range(2,5000001):
    if(sieve[i]==i):
        tmp=2
        while tmp*i<5000001:
            if(sieve[tmp*i]==tmp*i):
                sieve[tmp*i]=i
            tmp+=1

for item in n_list:
    while sieve[item]!=item:
        sys.stdout.write(f'{sieve[item]} ')
        item=item//sieve[item]
    sys.stdout.write(f'{sieve[item]} ')
    sys.stdout.write('\n')