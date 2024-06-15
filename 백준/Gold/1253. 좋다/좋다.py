num_size=int(input())
item_list=list(map(int,input().split()))

item_list.sort()

target_point=num_size-1
low=0
high=0
cnt=0

for i in range(num_size):
    low=0
    high=num_size-1
    while low<high:
        if item_list[low]+item_list[high]>item_list[i]:
            high-=1            
        elif item_list[low]+item_list[high] < item_list[i]:
            low+=1
        else:
            if low!=i and high!=i:
                cnt+=1
                break
            elif low==i:
                low+=1
            else:
                high-=1
    
print(cnt)
