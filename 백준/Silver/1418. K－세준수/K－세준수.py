import sys
n_list=[0]*100001
n_list[1]=1
for i in range(2,len(n_list)):
    if(n_list[i]==0):#this is prime number
        n_list[i]=i
        tmp=2
        while(i*tmp<=100000):
            n_list[i*tmp]=i
            tmp+=1
n=int(sys.stdin.readline())
k=int(sys.stdin.readline())
cnt=0
for item in n_list[1:n+1]:
    if(item<=k):
        cnt+=1
sys.stdout.write(f'{cnt}\n')