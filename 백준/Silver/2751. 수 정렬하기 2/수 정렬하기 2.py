import sys
input=sys.stdin.readline
print =sys.stdout.write

#input
num_size= int(input())
item_list=[]
for _ in range(num_size):
    item_list.append(int(input()))

#main
def mergesort(list1,low_idx,high_idx):
    '''
    post-order algorithm
    first, divide list into two segment
    '''
    mid_idx=(low_idx+high_idx)//2
    if(low_idx>=high_idx):
        return
    
    mergesort(list1,low_idx,mid_idx)
    mergesort(list1,mid_idx+1,high_idx)    
    mSort(list1,low_idx,high_idx)
    return list1

def mSort(list1,low_idx,high_idx):
    list1
    low_idx
    high_idx
    mid_idx=(low_idx+high_idx)//2
    i=low_idx
    j=mid_idx+1
    tmp=[]
    while (i<=mid_idx) and (j<=high_idx):
        if (list1[i]<=list1[j]):
            tmp.append(list1[i])
            i+=1
        else:
            tmp.append(list1[j])
            j+=1
    if i > mid_idx:#write right list
        tmp.extend(list1[j:high_idx+1])
    else: #write left list
        tmp.extend(list1[i:mid_idx+1])
    
    for k in range(len(tmp)):
        list1[low_idx+k]=tmp[k]
    return list1

mergesort(item_list,0,len(item_list)-1)
for i in range(num_size):
    print(f'{item_list[i]}\n')    