import sys
num=int(input())
num_list=list(map(int,sys.stdin.readline().split()))
set_list=list(set(num_list))
set_list.sort()

def bisearch(target):
    global set_list
    start=0
    end=len(set_list)-1
    while(start<=end):
        mid=(start+end)//2
        if(set_list[mid]>=target):
            end=mid-1
        else:
            start=mid+1
    return end

for i in range(num):
    sys.stdout.write(f'{bisearch(num_list[i])+1} ')