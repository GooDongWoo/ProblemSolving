import sys
number=1033750
n_list=[1]*number
n_list[0]=n_list[1]=0
for i in range(2,len(n_list)):
    if(n_list[i]==1):#this is prime number
        str_i=str(i)
        flag=True
        for j in range(len(str_i)//2):
            if(str_i[j]!=str_i[len(str_i)-1-j]):
                flag=False
                break
        if not (flag):
            n_list[i]=0
        tmp=2
        while((i*tmp)< number):
            n_list[(i*tmp)]=0
            tmp+=1
k=int(sys.stdin.readline())
cnt=0
for idx in range(k,len(n_list)):
    if(n_list[idx]==1):
        break
sys.stdout.write(f'{idx}\n')