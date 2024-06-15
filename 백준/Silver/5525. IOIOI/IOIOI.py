import sys
n=int(input())
m=int(input())
ioi_list=list(input().rstrip())
ioi_cnt_list=[]
ioi_cnt=0
idx=0
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