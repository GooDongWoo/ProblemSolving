import sys
l=[(1,20),(2,19),(3,21),(4,20),(5,21),(6,22),(7,23),(8,23),(9,23),(10,23),(11,23),(12,22)]
mem=[0]*12
for i in range(7):
    m,d=map(int,sys.stdin.readline().split())
    if(d>=l[m-1][1]):
        mem[(m-1)%12]+=1
    else:
        mem[(m-2)%12]+=1
res=[]
n=int(sys.stdin.readline())
for _ in range(n):
    m,d=map(int,sys.stdin.readline().split())
    if(d>=l[m-1][1] and not (mem[(m-1)%12])):
        res.append((m,d))
    elif(d<l[m-1][1] and not (mem[(m-2)%12])):
        res.append((m,d))
res.sort()
if(res):
    for i in range(len(res)):
        sys.stdout.write(f'{res[i][0]} {res[i][1]}\n')
else:
    sys.stdout.write(f'ALL FAILED\n')
