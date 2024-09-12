n=int(input())
pan_idx=n-1
pan=list(input().rstrip())

m=int(input())
target=list(input().rstrip())
target_idx=0

pan_set=set(pan)
target_set_list=list(set(target))
false_flag=0
for i in target_set_list:
    if i not in pan_set:
        false_flag=1
        break

if false_flag==1:
    print(-1)
else:
    tot_cnt=0
    while target_idx!=m:
        tot_cnt+=1
        pan_idx=(pan_idx+1)%n
        if(pan[pan_idx]==target[target_idx]):
            target_idx+=1

    print(tot_cnt)