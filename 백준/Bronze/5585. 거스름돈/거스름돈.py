n=int(input())
a=[500,100,50,10,5,1]
cnt=0
idx=0
n=1000-n
while n!=0:
    cnt+=n//a[idx]
    n=n%a[idx]
    idx+=1
print(cnt)