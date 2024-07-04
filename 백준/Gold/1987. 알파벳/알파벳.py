import sys
r,c=map(int,sys.stdin.readline().split())
map_mat=[list(map(lambda x:x-65,map(ord,list(sys.stdin.readline().rstrip())))) for _ in range(r)]
dict1=[0]*26
dy_dx=[(1,0),(0,1),(-1,0),(0,-1)]
max_cnter=0
def dfs(pr=0,pc=0,time=1):
    global r,c,map_mat,dict1,dy_dx,max_cnter
    if(dict1[map_mat[pr][pc]]==0):
        dict1[(map_mat[pr][pc])]=1
        max_cnter=max(max_cnter,time)
        if(max_cnter==26):
            return
        for dy,dx in dy_dx:
            if(0<=pr+dy<r and 0<=pc+dx<c and dict1[(map_mat[pr+dy][pc+dx])]==0):
                dfs(pr+dy,pc+dx,time+1)
        dict1[(map_mat[pr][pc])]=0
dfs()
sys.stdout.write(f'{max_cnter}')