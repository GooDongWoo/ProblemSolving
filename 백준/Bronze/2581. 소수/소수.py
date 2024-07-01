n=int(input())
m=int(input())
p_l=[1]*10001
p_l[0]=0
p_l[1]=0
prime_list=[]
for i in range(2,len(p_l)):
    if(p_l[i]):
        if(n<=i<=m):
            prime_list.append(i)
        t1=2
        while t1*i<=10000:
            p_l[t1*i]=0
            t1+=1
if(prime_list):
    print(sum(prime_list))
    print(prime_list[0])
else:
    print(-1)