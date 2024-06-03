import sys
dp_list=[[0 for _ in range(31)] for _ in range(31)]
#make dp_list(combination list)
for i in range(1,31):
    dp_list[i][0]=1
    dp_list[i][i]=1
for i in range(2,31):
    for j in range(1,i):
        dp_list[i][j]=dp_list[i-1][j-1]+dp_list[i-1][j]
test_case=int(input())        
for _ in range(test_case):
    a,b=map(int,sys.stdin.readline().split())
    sys.stdout.write(f'{dp_list[b][a]}\n')