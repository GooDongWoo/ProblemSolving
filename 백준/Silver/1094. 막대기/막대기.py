import heapq
x=int(input())
bar1=64
bar1_list=[64]
#heapq.heapify(bar1_list)
while 1:
    sum_of_bars=sum(bar1_list)
    if(sum_of_bars>x):
        minimum_of_list=heapq.heappop(bar1_list)
        if(sum(bar1_list)+(minimum_of_list/2)>=x):
            heapq.heappush(bar1_list,minimum_of_list/2)
        else:
            heapq.heappush(bar1_list,minimum_of_list/2)
            heapq.heappush(bar1_list,minimum_of_list/2)
    else:
        break
print(len(bar1_list))