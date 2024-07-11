from collections import deque
import sys
n,w,l=map(int,sys.stdin.readline().split())
wait=deque([*map(int,sys.stdin.readline().split())])
bridge=deque()
bw=0
time=0
while wait or bridge:
    #bridge에 있는 것 중에 제일 앞의 시간이 w가 지났으면 bridge에서 popleft한다.
    if(bridge and bridge[0][1]+w<=time):
        bw-=bridge[0][0]
        bridge.popleft()
    #만약 올릴 수 있으면 올린다.
    if(wait and bw+wait[0]<=l):
        bw+=wait[0]
        bridge.append((wait.popleft(),time))
    time+=1
print(time)