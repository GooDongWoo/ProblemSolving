import sys

set_1=set([])
for i in range(10):
    not_empty_num=int(sys.stdin.readline())
    not_empty_num=not_empty_num%42
    set_1.add(not_empty_num)

print(f'{len(set_1)}')
    