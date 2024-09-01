import sys
L=300000
ms_num=[0]*(L+1)
for i in range(L+1):
    if(i%7==1 or i%7==6):ms_num[i]=1
ms_prime_list=[]
for i in range(2,L+1):
    if(ms_num[i]==1):
        ms_prime_list.append(i)
        for j in range(i*2,L+1,i):
            ms_num[j]=0

while 1:
    t=int(sys.stdin.readline())
    if(t==1):break
    sys.stdout.write(f'{t}: ')
    idx=0
    while idx<len(ms_prime_list) and ms_prime_list[idx]<=t:
        if(t%ms_prime_list[idx]==0):
            sys.stdout.write(f'{ms_prime_list[idx]} ')
        idx+=1
    sys.stdout.write(f'\n')