import sys
input = sys.stdin.readline

n = int(input())
name = input().rstrip()
k = int(input())

if name =='annyong':
    if k & 1:
        print(k)
    else:
        print(k - 1)
else:
    if k == 1:
        print(k + 1)
    elif k & 1:
        print(k - 1)
    else:
        print(k)