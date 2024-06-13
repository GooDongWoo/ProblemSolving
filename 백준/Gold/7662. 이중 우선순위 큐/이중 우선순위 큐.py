import heapq
import sys

def D(flag):
    global min_p_q,max_p_q,item_cnt_dict,total_cnt
    if(flag==1):
        while 1:
            if(total_cnt):
                tmp=heapq.heappop(max_p_q)
                if(item_cnt_dict[-1*tmp]>0):
                    item_cnt_dict[-1*tmp]-=1
                    total_cnt-=1
                    return -1*tmp
            else:
                return 'EMPTY'
    elif(flag==-1):
        while 1:
            if(total_cnt):
                tmp=heapq.heappop(min_p_q)
                if(item_cnt_dict[tmp]>0):
                    item_cnt_dict[tmp]-=1
                    total_cnt-=1
                    return tmp
                    
            else:
                return 'EMPTY'

def I(target):
    global min_p_q,max_p_q,item_cnt_dict,total_cnt
    if(target in item_cnt_dict):
        item_cnt_dict[target]+=1
    else:
        item_cnt_dict[target]=1
    total_cnt+=1
    heapq.heappush(min_p_q,target)
    heapq.heappush(max_p_q,-1*target)

test_case=int(sys.stdin.readline())
func_dict={'D':D,'I':I}
for _ in range(test_case):
    cal_num=int(sys.stdin.readline())
    min_p_q=[]
    max_p_q=[]
    total_cnt=0
    item_cnt_dict=dict()
    for _ in range(cal_num):
        optr,oprnd=sys.stdin.readline().split()
        func_dict[optr](int(oprnd))
    if(total_cnt>1):
        sys.stdout.write(f'{D(1)} {D(-1)}\n')
    elif(total_cnt==1):
        tmp=D(1)
        sys.stdout.write(f'{tmp} {tmp}\n')
    elif(total_cnt==0):
        sys.stdout.write(f'EMPTY\n')