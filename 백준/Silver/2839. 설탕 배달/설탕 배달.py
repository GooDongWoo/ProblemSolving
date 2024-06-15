n=int(input())
a=[3,5]
min_num=(n//a[1])
num_vynl=10000
for i in range(min_num+1):
    if ((n-(i*a[1]))%a[0]==0):
        tmp=(n-(i*a[1]))//a[0]
        tmp+=i
        num_vynl=min(num_vynl,tmp)
if(num_vynl==10000):
    print(-1)
else:
    print(num_vynl)