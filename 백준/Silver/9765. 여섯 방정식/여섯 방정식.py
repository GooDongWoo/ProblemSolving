c1,c2,c3,c4,c5,c6=map(int,input().split())
primes=[]
candidates=[1]*20000001
candidates[0]=candidates[1]=0
for i in range(2,20000001):
    if(candidates[i]==1):
        primes.append(i)
        multi=2
        while multi*i<20000001:
            candidates[multi*i]=0
            multi+=1
x1c=[]
for i in range(len(primes)):
    if(c1%primes[i]==0):
        x1c.append(primes[i])
        break
x1c.append(c1//x1c[0])
if ((c5%x1c[0])==0):
    x1=x1c[1]
    x2=x1c[0]
    x3=c5//x1c[0]
else:
    x1=x1c[0]
    x2=x1c[1]
    x3=c5//x1c[1]

#################
x5c=[]
for i in range(len(primes)):
    if(c6%primes[i]==0):
        x5c.append(primes[i])
        break
x5c.append(c6//x5c[0])
if ((c3%x5c[0])==0):
    x5=x5c[1]
    x6=x5c[0]
    x7=c3//x5c[0]
else:
    x5=x5c[0]
    x6=x5c[1]
    x7=c3//x5c[1]

print(x1, x2, x3, x5, x6, x7)