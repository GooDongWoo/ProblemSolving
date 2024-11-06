import sys
input=sys.stdin.readline

a=input().rstrip()
b=input().rstrip()

for i in range(len(a)):
    sys.stdout.write(f'{int(a[i])&int(b[i])}')
sys.stdout.write(f'\n')

for i in range(len(a)):
    sys.stdout.write(f'{int(a[i])|int(b[i])}')
sys.stdout.write(f'\n')

for i in range(len(a)):
    sys.stdout.write(f'{int(a[i])^int(b[i])}')
sys.stdout.write(f'\n')

for i in range(len(a)):
    res=0 if int(a[i]) else 1
    sys.stdout.write(f'{res}')
sys.stdout.write(f'\n')

for i in range(len(a)):
    res=0 if int(b[i]) else 1
    sys.stdout.write(f'{res}')
sys.stdout.write(f'\n')