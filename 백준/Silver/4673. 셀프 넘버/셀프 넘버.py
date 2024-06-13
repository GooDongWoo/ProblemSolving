import sys
target_list=[1 for _ in range(10001)]
target_list[0]=0
for i in range(1,10001):
    if(target_list[i]!=0):
        next_num=i
        while(next_num<=10000):
            nxt_num_list=list(map(int,list(str(next_num))))
            next_num+=sum(nxt_num_list)
            if(next_num<=10000):
                if(target_list[next_num]==0):
                    break
                target_list[next_num]=0
            
for i in range(1,10001):
    sys.stdout.write(f'{i}\n') if target_list[i]!=0 else i