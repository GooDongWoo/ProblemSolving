import sys
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
target=list(map(int,sys.stdin.readline().split()))
same=[(a[i]==target[i]) for i in range(n)]
same_cnt=sum(same)
pass_flag=False

def merge(start, mid, end):
    global a,target,same,same_cnt,pass_flag
    i=start
    j=mid + 1
    t=0
    tmp=[0]*(end-start+1) # 임시 배열 tmp를 생성한다.
    while (i <= mid and j <= end):
        if (a[i] <= a[j]):
            tmp[t]=a[i] 
            i+=1
        else:
            tmp[t]=a[j] 
            j+=1
        t+=1
    if (i <= mid):  # 왼쪽 배열 부분이 남은 경우
        tmp[t:] = a[i:mid+1]
    if (j <= end):  # 오른쪽 배열 부분이 남은 경우
        tmp[t:] = a[j:end+1]
    i=start
    t=0
    while i<=end:
        if(same[i]==True and tmp[t]!=target[i]):# same -> not same --> cnt down
            same[i]=False
            same_cnt-=1
        elif(same[i]==False and tmp[t]==target[i]): # not same -> same --> cnt up
            same[i]=True
            same_cnt+=1
        a[i]=tmp[t]
        i+=1
        t+=1
        if(same_cnt==n):
            pass_flag=True
            return
def merge_sort(start,end):
    global a
    if (start < end and pass_flag==False):
        mid =(start + end)//2       # mid는 start, r의 중간 지점
        merge_sort(start, mid)      # 전반부 정렬
        merge_sort(mid + 1, end)  # 후반부 정렬
        merge(start, mid, end)        # 병합
if(same_cnt==n):
    pass_flag=True
merge_sort(0,len(a)-1)
print(int(pass_flag))