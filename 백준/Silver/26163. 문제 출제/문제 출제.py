b=[*map(int,input().split())]
#브루트포스
a=[0]*5

candidates=[]
for i in range(16):
    for j in range(8):
        for k in range(6):
            for l in range(4):
                for m in range(4):
                    n_sum=i+j+k+l+m
                    if(2<=n_sum<=3 and (i*1)+(j*2)+(k*3)+(l*4)+(m*5)<=10):#총문제를 3문제 이하로 낼때
                        candidates.append((i*b[0])+(j*b[1])+(k*b[2])+(l*b[3])+(m*b[4]))
                    elif(4<=n_sum and (i*1)+(j*2)+(k*3)+(l*4)+(m*5)<=15):#총문제를 4문제 이상으로 제출할때 
                        candidates.append((i*b[0])+(j*b[1])+(k*b[2])+(l*b[3])+(m*b[4]))
print(max(candidates))