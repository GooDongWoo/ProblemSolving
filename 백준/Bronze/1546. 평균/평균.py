import sys

test_num=int(sys.stdin.readline())

test_list=list(map(int,sys.stdin.readline().split()))
max_num=max(test_list)
for i in range(len(test_list)):
    test_list[i]=test_list[i]/max_num*100
print(sum(test_list)/len(test_list))