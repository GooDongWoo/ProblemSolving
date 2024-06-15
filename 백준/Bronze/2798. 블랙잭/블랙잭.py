n_test,M=map(int,input().split())
item_list=list(map(int,input().split()))
max_sum=0
for i in range(n_test-2):
    for j in range(i+1,n_test-1):
        for k in range(j+1,n_test):
            tmp=item_list[i]+item_list[j]+item_list[k]
            if (tmp<=M) and (tmp>max_sum):
                max_sum=tmp
print(max_sum)