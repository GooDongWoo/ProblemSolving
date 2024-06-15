import sys
from collections import deque
test_case=int(input())
for _ in range(test_case):
    m,n,k=map(int,input().split())
    baechu_mat=[[0 for _ in range(m)] for _ in range(n)]
    stck1=deque()
    set1=set()
    move=[(1,0),(0,1),(-1,0),(0,-1)]
    for _ in range(k):
        col,row=map(int,sys.stdin.readline().split())
        set1.add((row,col))
        baechu_mat[row][col]=1

    cnt=0
    while(set1):
        tmp=set1.pop()# set1 -> visit array 
        set1.add(tmp)
        stck1.append(tmp)
        cnt+=1
        while(stck1):
            tmp=stck1.pop()
            if(tmp in set1): # not visit
                set1.discard(tmp)
                #tmp의 자식들에 대해 for문
                for dir in range(len(move)):
                    if((tmp[0]+move[dir][0],tmp[1]+move[dir][1]) in set1):
                        stck1.append((tmp[0]+move[dir][0],tmp[1]+move[dir][1]))
    sys.stdout.write(f'{cnt}\n')