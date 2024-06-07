import sys
n=int(input())
meeting_list=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
#f_meeting_list=sorted(meeting_list,key=lambda x: (x[0],x[1])) -> 의미 없네;; 생각해보니 중요한 게 아님;;
l_meeting_list=sorted(meeting_list,key=lambda x: (x[1],x[0]))#-> 이게 중요하네


#dp_list=[0]*(2**31)-> 메모리 너무 사용하는데? dp로 하려했는데;;
#greedy넹 생각해보닝

#lg n 만에 끝내고 싶엇는데 list[n][1]은 정렬되는데 list[n][0]이 정렬 안되니 알고리즘 폐기;; n으로 순차적으로 검색 간다.
# def biSearch(target,low,high,item_idx):
#     global n,l_meeting_list
#     while low<=high:
#         mid=(low+high)//2
#         if(l_meeting_list[mid][item_idx]>=target):
#             high=mid-1
#         else:
#             low=mid+1
#     return low,l_meeting_list[low][0],l_meeting_list[low][1]

#가장 처음
#f_meeting_list[0]#-> return (가장 빠른 시작,그중에서 제일 먼저 끝..)
#l_meeting_list[0][1]#-> return (그 중에서 제일 먼저 시작,제일 먼저 끝나는..)
cnt=1
cur_able_time=l_meeting_list[0][1]

for i in range(1,len(meeting_list)):
    if(cur_able_time<=l_meeting_list[i][0]): #l_meeting_list[i][0]: start time
        cur_able_time=l_meeting_list[i][1]
        cnt+=1
print(cnt)