from collections import deque
n=int(input())
fruit_list=list(map(int,input().split()))

cnt=t_cnt=tmp=1
chck_list=set()
chck_list.add(fruit_list[0])
q1=deque([fruit_list[0]])

for i in range(1,len(fruit_list)):
    chck_list.add(fruit_list[i])
    if(len(chck_list)<=2):
        q1.append(fruit_list[i])
        cnt+=1
        if(fruit_list[i]==fruit_list[i-1]):
            tmp+=1
        else:
            tmp=1
        t_cnt=max(t_cnt,cnt)
    else:
        chck_list=set([q1.pop()])
        q1=deque(list(chck_list))
        t_cnt=max(t_cnt,cnt)
        
        chck_list.add(fruit_list[i])
        q1.append(fruit_list[i])
        cnt=tmp+1
        tmp=1
        
print(t_cnt)