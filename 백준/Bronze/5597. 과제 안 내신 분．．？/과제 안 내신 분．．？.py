import sys
list_=[0]*30
for i in range(28):
    not_empty_num=int(sys.stdin.readline())
    list_[not_empty_num-1]= 1
for i in (range(30)):
    if list_[i]==0:
        print(f'{i+1}')
    