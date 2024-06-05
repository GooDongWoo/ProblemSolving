n=int(input())
fruit_list=list(map(int,input().split()))

cnt=t_cnt=tmp=1
chck_list=set()
chck_list.add(fruit_list[0])
for i in range(1,len(fruit_list)):
    chck_list.add(fruit_list[i])
    if(len(chck_list)<=2):
        cnt+=1
        if(fruit_list[i]==fruit_list[i-1]):
            tmp+=1
        else:
            tmp=1
        t_cnt=max(t_cnt,cnt)
    else:
        chck_list=set([fruit_list[i-1]])
        t_cnt=max(t_cnt,cnt)
        
        chck_list.add(fruit_list[i])
        cnt=tmp+1
        tmp=1
        
print(t_cnt)