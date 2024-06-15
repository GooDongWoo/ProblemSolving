from sys import stdin, stdout
from collections import deque
print = stdout.write
input = stdin.readline

#define min-heap data structure
class heap():
    def __init__(self,arr):
        self.arr=arr
        self.heapify()
        
    def heapify(self):
        self.size = len(self.arr)
        self.first_node_idx=self.size // 2 -1
        self.odd=self.size%2
        if self.odd:
            smallest=self.arr[self.first_node_idx]
            if smallest > self.arr[self.first_node_idx*2 +1]:
                smallest = self.arr[self.first_node_idx*2 +1]
                self.arr[self.first_node_idx],self.arr[self.first_node_idx*2 +1]=self.arr[self.first_node_idx*2 +1],self.arr[self.first_node_idx]
            if smallest > self.arr[self.first_node_idx*2 +2]:
                smallest = self.arr[self.first_node_idx*2 +2]
                self.arr[self.first_node_idx],self.arr[self.first_node_idx*2 +2]=self.arr[self.first_node_idx*2 +2],self.arr[self.first_node_idx]
        else:
            smallest=self.arr[self.first_node_idx]
            if smallest > self.arr[self.first_node_idx*2 +1]:
                smallest = self.arr[self.first_node_idx*2 +1]
                self.arr[self.first_node_idx],self.arr[self.first_node_idx*2 +1]=self.arr[self.first_node_idx*2 +1],self.arr[self.first_node_idx]
                
        for i in range(self.first_node_idx-1,-1,-1):
            smallest=self.arr[i]
            if smallest > self.arr[i*2 +1]:
                smallest = self.arr[i*2 +1]
                self.arr[i],self.arr[i*2 +1]=self.arr[i*2 +1],self.arr[i]
            if smallest > self.arr[i*2 +2]:
                smallest = self.arr[i*2 +2]
                self.arr[i],self.arr[i*2 +2]=self.arr[i*2 +2],self.arr[i]
                
    def insert(self,item):
        if len(self.arr) !=0:
            self.arr.append(item)
            self.heapify()
            self.size+=1
        else:
            self.arr=[item]
            
    def delete(self,item):
        pointer=-1
        for i in range(len(self.arr)):
            if item == self.arr[i]:
                pointer=i
                break
        if pointer ==-1:
            raise ValueError(f'there is no {item} in arr')
        self.arr[pointer],self.arr[len(self.arr)-1]=self.arr[len(self.arr)-1],self.arr[pointer]
        self.arr.pop()
        self.heapify()
        
    def minPrint(self):
        return self.arr[0]

#######################################################

list_length, sub_length=map(int,input().split())
item_list=list(map(int,input().split()))

d_list=deque([(0,item_list[0])])
print(str(d_list[0][1])+" ")
for idx, i in enumerate(item_list[1:],1):
    #만약 새로들어오는 i가 기존 맨뒤의 값보다 크면 멈추고 거기에 넣고 작으면 pop하고 다시 반복... 만약 dlist가 []되면 그냥 멈추고 넣는다.
    if (idx-d_list[0][0]+1)>sub_length:
        d_list.popleft()
    tmp=len(d_list)
    while tmp!=0:
        if i > d_list[tmp-1][1]:
            break
        else:
            tmp-=1
            d_list.pop()
    d_list.append((idx,i))
    print(str(d_list[0][1])+" ")