import sys
import heapq
input= sys.stdin.readline
print=sys.stdout.write

arr_size=int(input())
arr=[]

#accept input arr
for i in range(arr_size):
    arr.append(int(input()))

heap1=[]
def thres(x):
    if x<0:
        return -1*x -0.5
    else:
        return x
    
for i in range(arr_size):
    if arr[i]==0:
        try:
            print(f'{heapq.heappop(heap1)[1]}\n')
        except:
            print(f'{0}\n')
    else:
        heapq.heappush(heap1,(thres(arr[i]),arr[i]))