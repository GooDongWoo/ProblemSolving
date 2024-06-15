import sys
input = sys.stdin.readline

num_item, target= map(int, input().split())
item_list = list(map(int, input().split()))

tmp_sum =0
count_list=[0]*target

for i in range(num_item):
    tmp_sum=(tmp_sum+item_list[i])%target
    count_list[tmp_sum]+=1

result = count_list[0]
for i in (count_list):
    result+=i*(i-1)//2

print(result)