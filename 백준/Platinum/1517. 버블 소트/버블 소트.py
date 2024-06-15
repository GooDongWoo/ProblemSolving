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
''''
하나가 올라가면 나머지는 1개씩 인덱스가 줄어든다.. 그리고 그렇기에 초기 인덱스와 최종 인덱스만을 비교하면 차이가 존재한다. 이 아이디어는 폐기..
아이템리스트를 순회하며 각 i번쨰 인덱스에서 그 인덱스에 해당하는 아이템을(n)
sorted에서 bibary search하는 거임..(log(n))
그리고 그 sorted_index랑 i의 차이를 구해서 max(0, sorted_index - i)를 sum하는 거임
중복된 것은 dict로 +1?
'''
'''
#using set DS
sorted_idx={}
for i in range(num_size):
    if sorted_list[i]>=0:
        sorted_idx.update({sorted_list[i]:i})
    else:# negetive num
        sorted_idx.update({(1000000000-sorted_list[i]):i})

#sum of total right direction move
tmp=0
for i in range(num_size):
    if item_list[i]>=0:
        tmp+=max(0,sorted_idx[item_list[i]]-i)
    else:# negetive num
        tmp+=max(0,sorted_idx[(1000000000-sorted_list[i])]-i)
    
print(f'{tmp}')'''

#memort issue-> aborted WTF
'''sorted_idx=[0]*2000000000
for i in range(num_size):
    if sorted_list[i]>=0:
        sorted_idx[sorted_list[i]]=i
    else:# negetive num
        sorted_idx[1000000000-sorted_list[i]]=i

#sum of total right direction move
tmp=0
for i in range(num_size):
    if item_list[i]>=0:
        tmp+=max(0,sorted_idx[item_list[i]]-i)
    else:# negetive num
        tmp+=max(0,sorted_idx[1000000000-item_list[i]]-i)
    
print(f'{tmp}')

'''