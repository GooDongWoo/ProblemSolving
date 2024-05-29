import sys
num_house=int(input())
cost_list=[list(map(int,sys.stdin.readline().split())) for _ in range(num_house)]
rgb_house_list=[0]*num_house # 0:r, 1:g, 2:b
optimum_cost_list=[[0 for _ in range(3)] for _ in range(num_house)]

optimum_cost_list[0]=cost_list[0]
for house_num in range(1,num_house):
    for color in range(3):
        optimum_cost_list[house_num][color]= min(optimum_cost_list[house_num-1][(color+1)%3]+cost_list[house_num][color],optimum_cost_list[house_num-1][(color+2)%3]+cost_list[house_num][color])

print(min(optimum_cost_list[-1]))