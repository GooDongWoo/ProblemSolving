import sys
input = sys.stdin.readline
print=sys.stdout.write
item_size, kth=map(int,input().split())
item_list=list(map(int,input().split()))
item_list.sort()
print(f'{item_list[kth-1]}')