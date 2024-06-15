sum_1=int(input())
iter=int(input())
tmp=0
for i in range(iter):
    para_1,para_2=input().split()
    para_1=int(para_1)
    para_2=int(para_2)
    tmp+=para_1*para_2
if tmp==sum_1:
    print("Yes")
else:
    print("No")