import sys
test_case=int(input())
for _ in range(test_case):
    x1,y1,r1,x2,y2,r2=map(int,sys.stdin.readline().split())
    if((x1,y1)==(x2,y2)):
        if(r1==r2):
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'0\n')
    else:
        if((r1+r2)==(((x1-x2)**2+(y1-y2)**2)**(1/2)) or abs(r1-r2)==(((x1-x2)**2+(y1-y2)**2)**(1/2))):
            sys.stdout.write(f'1\n')
        elif(((x1-x2)**2+(y1-y2)**2)**(1/2)>(r1+r2) or (((x1-x2)**2+(y1-y2)**2)**(1/2)+(min(r1,r2))<max(r1,r2))):
            sys.stdout.write(f'0\n')
        else:
            sys.stdout.write(f'2\n')