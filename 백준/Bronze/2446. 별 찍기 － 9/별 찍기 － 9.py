import sys
n=int(sys.stdin.readline())
for i in range(n):
    sys.stdout.write(f'{" "*i}{"*"*(2*(n-i)-1)}\n')
for i in range(2,n+1):
    sys.stdout.write(f'{" "*(n-i)}{"*"*(2*i -1)}\n')