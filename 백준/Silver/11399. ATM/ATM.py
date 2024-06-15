num_size=int(input())
items_list=list(map(int,input().split()))

items_list.sort()
sum_list=[0]*num_size
sum_list[0]=items_list[0]
for i in range(1,num_size):
    sum_list[i]=sum_list[i-1]+items_list[i]
tmp=0
for i in range(num_size):
    tmp+=sum_list[i]
print(tmp)