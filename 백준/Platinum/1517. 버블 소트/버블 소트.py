import sys
print= sys.stdout.write
input= sys.stdin.readline

num_size=int(input())
item_list=list(map(int,input().split()))
result=0
def mergeSort(list1,low_idx,high_idx):
    mid_idx=(low_idx+high_idx)//2
    if low_idx >=high_idx:
        return
    
    mergeSort(list1,low_idx,mid_idx)
    mergeSort(list1,mid_idx+1, high_idx)
    merge(list1,low_idx,high_idx)
    return list1

def merge(list1,low_idx,high_idx):
    mid_idx=(low_idx+high_idx)//2
    i=low_idx
    j=mid_idx+1
    k=0
    tmp=[0]*(high_idx-low_idx+1)
    global result
    while (i<=mid_idx) and (j<=high_idx):
        if (list1[i]<=list1[j]):
            tmp[k]=list1[i]
            k+=1
            i+=1
        else:
            tmp[k]=list1[j]
            k+=1
            j+=1
            result +=(mid_idx-i+1)
    if (i>mid_idx): #push right list to tmp
        for p in range(k,len(tmp)):
            tmp[p]=list1[j]
            j+=1
    else:
        for p in range(k,len(tmp)):
            tmp[p]=list1[i]
            i+=1
    for p in range(len(tmp)):
        list1[low_idx+p]=tmp[p]
    return list1

mergeSort(item_list,0,len(item_list)-1)
print(f'{result}')