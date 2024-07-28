def makeDragonCurve(x,y,d,g):
    global arr
    dy=[0,-1,0,1]
    dx=[1,0,-1,0]
    dots=[(y,x)]
    dots.append((dots[-1][0]+dy[d],dots[-1][1]+dx[d]))
    for _ in range(g):
        std_r,std_c=dots[-1][0],dots[-1][1]
        for i in range(len(dots)-2,-1,-1):
            rel_r,rel_c=-std_r+dots[i][0],-std_c+dots[i][1]
            abs_r,abs_c=std_r+rel_c,std_c-rel_r
            dots.append((abs_r,abs_c))
    for row,col in dots:
        arr[row][col]=1

def cnt1():
    global arr
    cnt=0
    for i in range(100):
        for j in range(100):
            if(arr[i][j] and arr[i][j+1] and arr[i+1][j] and arr[i+1][j+1]):
                cnt+=1
    print(cnt)
    return

import sys
n=int(sys.stdin.readline())
arr=[[0]*101 for _ in range(101)]
for _ in range(n):
    x,y,d,g=map(int,sys.stdin.readline().split())
    makeDragonCurve(x,y,d,g)
cnt1()