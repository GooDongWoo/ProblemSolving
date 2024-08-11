import sys
n=int(input())
pots=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cnt=0
target_num=[0]*1000001
for i in range(n):
    if not (target_num[pots[i][0]] or target_num[pots[i][1]] or target_num[pots[i][2]]):
        cnt+=1
    for j in pots[i]:
        target_num[j]=1
sys.stdout.write(f'{cnt}')