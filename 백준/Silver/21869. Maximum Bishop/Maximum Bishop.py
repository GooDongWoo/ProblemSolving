import sys
n=int(sys.stdin.readline())
if(n>1):
    sys.stdout.write(f'{n+(n-2)}\n')
    for i in range(1,n+1):
        sys.stdout.write(f'1 {i}\n')
    for i in range(2,n):
        sys.stdout.write(f'{n} {i}\n')
else:
    sys.stdout.write(f'{n}\n')
    sys.stdout.write(f'1 1')