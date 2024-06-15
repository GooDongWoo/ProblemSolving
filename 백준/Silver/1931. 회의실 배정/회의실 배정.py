import sys
n=int(input())
meeting_list=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
#f_meeting_list=sorted(meeting_list,key=lambda x: (x[0],x[1])) -> 의미 없네;; 생각해보니 중요한 게 아님;;
l_meeting_list=sorted(meeting_list,key=lambda x: (x[1],x[0]))#-> 이게 중요하네


cnt=1
cur_able_time=l_meeting_list[0][1]

for i in range(1,len(meeting_list)):
    if(cur_able_time<=l_meeting_list[i][0]): #l_meeting_list[i][0]: start time
        cur_able_time=l_meeting_list[i][1]
        cnt+=1
print(cnt)