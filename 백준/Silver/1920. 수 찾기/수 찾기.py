import sys

n=int(input())

A=list(map(int,sys.stdin.readline().split()))

M=int(input())
set_a=set(A)
res=list(map(int,sys.stdin.readline().split()))
for i in res:
    if(i in set_a):
        sys.stdout.write(f'1\n')
    else:
        sys.stdout.write(f'0\n')