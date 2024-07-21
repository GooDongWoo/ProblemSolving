import sys
t=int(sys.stdin.readline())
for _ in range(t):
    n,m=map(int,sys.stdin.readline().split())
    for _ in range(m):
        sys.stdin.readline()
    sys.stdout.write(f'{n-1}\n')