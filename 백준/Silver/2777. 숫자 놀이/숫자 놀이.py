import sys
primes=[2,3,5,7]
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    if(n<10):
        print(1)
        continue
    dict1=dict()
    for i in primes:
        dict1[i]=0
    over_prime_flag=0
    while n!=1 and not(over_prime_flag):
        for i in primes:
            if n%i==0:
                dict1[i]+=1
                n=n//i
                break
            elif i==7:
                over_prime_flag=1
    if(over_prime_flag):
        print(-1)
    else:
        if(dict1[2]>=3):
            tmp=(dict1[2]//3)
            dict1[2]-=tmp*3
            dict1[8]=tmp
        if(dict1[2]>=2):
            tmp=(dict1[2]//2)
            dict1[2]-=tmp*2
            dict1[4]=tmp
        if(dict1[2]>=1 and dict1[3]>=1):
            tmp=min(dict1[2],dict1[3])
            dict1[6]=tmp
            dict1[2]-=tmp
            dict1[3]-=tmp
        if(dict1[3]>=2):
            tmp=(dict1[3]//2)
            dict1[3]-=tmp*2
            dict1[9]=tmp
        print(sum([item for item in dict1.values()]))