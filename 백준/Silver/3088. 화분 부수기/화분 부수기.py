import sys
n=int(input())
pots=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cnt=0
target_num=[0]*1000001
for i in range(n):
    chck=any([(target_num[j]==1) for j in pots[i]])
    if not (chck):
        cnt+=1
    for j in pots[i]:
        target_num[j]=1
sys.stdout.write(f'{cnt}')