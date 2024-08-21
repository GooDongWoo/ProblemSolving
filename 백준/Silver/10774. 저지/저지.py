import sys
j=int(sys.stdin.readline())
a=int(sys.stdin.readline())
js=[0]*j
d1=dict()
d1['S']=0
d1['M']=1
d1['L']=2
for i in range(j):
    js[i]=d1[sys.stdin.readline().rstrip()]
av=[1]*j
for _ in range(a):
    size,num=sys.stdin.readline().rstrip().split()
    num=int(num)
    if(av[num-1]==1 and d1[size]<=js[num-1]):
        av[num-1]=0
print(j-sum(av))