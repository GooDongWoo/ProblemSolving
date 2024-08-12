def bs(l1,target): #bs_r
    end=len(l1)-1
    start=0
    while start<=end:
        mid =(start+end)//2
        if(l1[mid]<=target):
            start=mid+1
        else:
            end=mid-1
    return start

n=int(input())
needs=sorted([*map(int,input().split())])
sum_arr=[0]*n
sum_arr[0]=needs[0]
for i in range(1,n):
    sum_arr[i]=sum_arr[i-1]+needs[i]

total_limit=int(input())
t_sum=sum(needs)
if(t_sum<=total_limit):
    print(needs[-1])
else:
    start=total_limit//n
    end=needs[-1]
    while start<=end:
        mid=(start+end)//2
        idx=bs(needs,mid)
        origin_sum= sum_arr[idx-1] if idx>0 else 0
        if((origin_sum+(mid)*(n-idx))<=total_limit):
            start=mid+1
        else:
            end=mid-1
    print(end)