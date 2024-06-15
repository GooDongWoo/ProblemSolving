import sys
n=int(sys.stdin.readline())
wine_list=[0 for _ in range(n)]
for i in range(n):
    wine_list[i]=int(sys.stdin.readline())
dp_list=[[0 for _ in range(3)] for _ in range(n)]#그 번째에 안마신다 , 그번째에 마시는데 그 마신 것이 첫번째로 마시는것, 그번째에 마시는데 그 마신 것이 두번째로 마시는것
dp_list[0][1]=dp_list[0][2]=wine_list[0]
for i in range(1,n):
    dp_list[i][0],dp_list[i][1],dp_list[i][2]=max(dp_list[i-1]),dp_list[i-1][0]+wine_list[i],dp_list[i-1][1]+wine_list[i]
sys.stdout.write(f'{max(dp_list[-1])}')