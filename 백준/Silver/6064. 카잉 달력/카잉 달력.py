import sys
test_case=int(input())
for _ in range(test_case):
    find_flag=0
    target_a=-1
    n,m,x,y=map(int,sys.stdin.readline().split())
    for i in range(m+1):
        if((((n*i)+x)-y)%m==0):
            sys.stdout.write(f'{((n*i)+x)}\n')
            find_flag=1
            break
    if not (find_flag):
        sys.stdout.write(f'-1\n')