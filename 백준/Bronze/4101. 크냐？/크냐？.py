import sys
while 1:
    a,b=map(int,sys.stdin.readline().split())
    if(a==0 and b==0):
        break
    else:
        sys.stdout.write(f'Yes\n') if a>b else sys.stdout.write(f'No\n')