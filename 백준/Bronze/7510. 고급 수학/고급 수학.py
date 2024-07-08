import sys
t=int(sys.stdin.readline())
for i in range(t):
    a_list=sorted(list(map(int,input().split())))
    if(a_list[2]**2==(a_list[0]**2)+(a_list[1]**2)):
        print(f'Scenario #{i+1}:')
        print('yes')
        print()
    else:
        print(f'Scenario #{i+1}:')
        print('no')
        print()