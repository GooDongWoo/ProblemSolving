from collections import deque
tmp_list=input()
list_num=deque()
list_optr=[]
tmp=""
for chr in tmp_list:
    if(chr=="-" or chr=="+"):
        list_optr.append(chr)
        list_num.append(int(tmp))
        tmp=""
    else:
        tmp+=chr
list_num.append(int(tmp))

tmp=0
result=list_num.popleft()
for each_optr in list_optr:
    if(each_optr=='+'):
        result+=list_num.popleft()
    else:
        while(list_num):
            result-=list_num.popleft()
        break
print(result)