import sys
inf=int(1e8)
n,s=map(int,sys.stdin.readline().split())
item_list=list(map(int,sys.stdin.readline().split()))
sum_list=[0]*(n+1)
for idx in range(1,len(sum_list)):
    sum_list[idx]=sum_list[idx-1]+item_list[idx-1]
possible_val=inf
start=0
end=1
while(start<=end and end<n+1 and start<n+1):
    if(sum_list[end]-sum_list[start]<s):#end를 늘려서 될때까지 늘린다.
        end+=1
    elif(sum_list[end]-sum_list[start]>=s):
        possible_val=min(end-start,possible_val)
        start+=1
sys.stdout.write(f'{possible_val}') if possible_val!=inf else sys.stdout.write(f'0')