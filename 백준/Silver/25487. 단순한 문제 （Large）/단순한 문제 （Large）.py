import sys
n=int(input())
for _ in range(n):
    a,b,c=map(int,sys.stdin.readline().split())
    sys.stdout.write(f'{min(a,b,c)}\n')