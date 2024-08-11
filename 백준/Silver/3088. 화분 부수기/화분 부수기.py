import sys
n=int(input())
number_each_idx=[[] for _ in range(1000001)]
pots=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cnt=0
target_num=set()
for i in range(n):
    chck=any([(j in target_num) for j in pots[i]])
    if not (chck):
        cnt+=1
    
    for j in pots[i]:
        target_num.add(j)
sys.stdout.write(f'{cnt}')