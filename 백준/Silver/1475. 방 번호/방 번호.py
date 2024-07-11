import sys
words=[*map(int,[*input().rstrip()])]
num_list=[0]*10
for i in words:
    if i==9:
        num_list[6]+=1
    else:
        num_list[i]+=1
if(num_list[6]&1):
    num_list[6]=num_list[6]//2+1
else:
    num_list[6]=num_list[6]//2
print(max(num_list))