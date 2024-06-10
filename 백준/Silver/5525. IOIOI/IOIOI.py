import sys
n=int(input())
m=int(input())
ioi_list=list(input().rstrip())
ioi_cnt_list=[]
ioi_cnt=0
idx=0
# i가 0부터 m-1까지 이동하면서 ioioioioi....가 연속으로 몇개까지 연결 되어있는지 확인한다.
# 만약 끊기면 지금까지의 연속 ioioi...의 연속 기록을 list에 append하고 새로 연속기록을 0으로 초기화한다.
# O(n)이 되면 리스트를 뒤져서 컴비네이션 수학으로 하나의 연속된 곳에서 구하고 이를 모든 리스트 아이템에 적용한다. 
# 그리고 프린트한다...
def chckIOI(idx):
    global ioi_list
    if(idx+2<=m-1):
        if(ioi_list[idx:idx+3]==['I','O','I']):
            return True
        else:
            return False
    else:
        return False

while idx<(m-2):
    if(ioi_list[idx]=='I'):
        while (chckIOI(idx)):
            idx+=2
            ioi_cnt+=1
        if(ioi_cnt):
            ioi_cnt_list.append(ioi_cnt)
            ioi_cnt=0
        idx+=1
    else:
        idx+=1
        
result=0
for cnt_item in ioi_cnt_list:
    if(cnt_item>=n):
        result+=(cnt_item-n+1)
print(result)