item_size = int(input())
target = int(input())
target_list = list(map(int,input().split()))

target_list.sort()

low=0
high=item_size-1
cnt=0
while (low<high):
    if target_list[low]+target_list[high]==target:
        cnt+=1
        low+=1
        high-=1
    elif target_list[low]+target_list[high]<target:
        low+=1
    else:
        high-=1
        
print(cnt)