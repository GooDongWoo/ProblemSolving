import sys
f_list=[[1,0],[0,1]]
f_list+=[[0,0] for _ in range(39)]
for i in range(2,41):
    f_list[i][0]+=f_list[i-1][0]+f_list[i-2][0]
    f_list[i][1]+=f_list[i-1][1]+f_list[i-2][1]

T=int(input())

for _ in range(T):
    tmp=int(sys.stdin.readline())
    sys.stdout.write(f'{f_list[tmp][0]} {f_list[tmp][1]}\n')