import sys
from collections import deque
from bisect import bisect_left,bisect_right
test_case=int(sys.stdin.readline())
#x,y를 리스트-> 정수형 m자리 숫자로 변환
def list2Int(list1):
    length=len(list1)
    result=0
    for i in range(len(list1)):
        result+=list1[i]*(10**(length-1-i))
    return result

for _ in range(test_case):
    n,m=map(int,sys.stdin.readline().split())
    x=list(map(int,sys.stdin.readline().split()))
    x=list2Int(x)
    y=list(map(int,sys.stdin.readline().split()))
    y=list2Int(y)
    dolimpan=deque(list(map(int,sys.stdin.readline().split())))
    target_num_list=[]
    #dolimpan에서 돌림판 사이즈만큼 로테이팅해서 구해본다. 
    for i in range(len(dolimpan)):
        tmp=[]
        for _ in range(m):
            tmp.append(dolimpan[0])
            dolimpan.rotate(-1)
        target_num_list.append(list2Int(tmp))
        dolimpan.rotate(m)
        dolimpan.rotate(-1)
    target_num_list.sort()
    first=bisect_left(target_num_list,x)
    last=bisect_right(target_num_list,y)
    sys.stdout.write(f'{last-first}\n')