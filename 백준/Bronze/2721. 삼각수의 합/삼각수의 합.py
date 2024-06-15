t_list=[0]*302
t_list[1]=1
for i in range(2,302):
    t_list[i]=t_list[i-1]+i
w_list=[0]*301
w_list[1]=1*t_list[2]
for i in range(2,301):
    w_list[i]=w_list[i-1]+i*t_list[i+1]

test_case=int(input())
for _ in range(test_case):
    print(w_list[int(input())])