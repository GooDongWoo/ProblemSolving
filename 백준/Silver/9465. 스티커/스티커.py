import sys
test_case=int(input())

for _ in range(test_case):
    n=int(input())
    sticker_list=[list(map(int,sys.stdin.readline().split())) for _ in range(2)]
    if(n==1):
        sys.stdout.write(f'{max(sticker_list[0][0],sticker_list[1][0])}\n')
        continue    
    dp_cost_list=[[-1 for _ in range(n)] for _ in range(3)]#3 X n mat// [0][k]: pick 0th st, [1][k] pick 1th st, [2][k] pick no sticker
    dp_cost_list[0][0]= sticker_list[0][0]
    dp_cost_list[1][0]= sticker_list[1][0]
    dp_cost_list[2][0]= 0
    
    dp_cost_list[0][1]= dp_cost_list[1][0]+sticker_list[0][1]
    dp_cost_list[1][1]= dp_cost_list[0][0]+sticker_list[1][1]
    dp_cost_list[2][1]= max(dp_cost_list[0][0],dp_cost_list[1][0])
    
    for idx in range(2,n):
        dp_cost_list[0][idx]= max(dp_cost_list[1][idx-1],max(dp_cost_list[0][idx-2],dp_cost_list[1][idx-2],dp_cost_list[2][idx-2])) + sticker_list[0][idx]
        dp_cost_list[1][idx]= max(dp_cost_list[0][idx-1],max(dp_cost_list[0][idx-2],dp_cost_list[1][idx-2],dp_cost_list[2][idx-2])) + sticker_list[1][idx]
        dp_cost_list[2][idx]= max(dp_cost_list[1][idx-1],dp_cost_list[0][idx-1]) + 0
    res=max(dp_cost_list[0][-1],dp_cost_list[1][-1],dp_cost_list[2][-1])
    sys.stdout.write(f'{res}\n')