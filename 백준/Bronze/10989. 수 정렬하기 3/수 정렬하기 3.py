import sys
input=sys.stdin.readline
print=sys.stdout.write

num_size=int(input())
item_list=[0]*10001

for _ in range(num_size):
    item_list[int(input())]+=1
    
for i in range(1,10001):
    while item_list[i]:
        print(f'{i}\n')
        item_list[i]-=1