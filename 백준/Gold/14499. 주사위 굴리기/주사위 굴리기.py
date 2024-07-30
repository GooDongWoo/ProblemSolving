class dice():
    def __init__(self):
        self.up=0
        self.down=0
        self.front=0
        self.back=0
        self.right=0
        self.left=0
    def rotate(self,num):
        if(num==1):
            self.rotateH(right=True)
        elif(num==2):
            self.rotateH(right=False)
        elif(num==3):
            self.rotateV(up=True)
        else:
            self.rotateV(up=False)
            
    def rotateH(self,right):
        if(right):
            tmp=self.up
            self.up=self.left
            self.left=self.down
            self.down=self.right
            self.right=tmp
        else:
            tmp=self.up
            self.up=self.right
            self.right=self.down
            self.down=self.left
            self.left=tmp
            
    def rotateV(self,up):
        if(up):
            tmp=self.up
            self.up=self.back
            self.back=self.down
            self.down=self.front
            self.front=tmp
        else:
            tmp=self.up
            self.up=self.front
            self.front=self.down
            self.down=self.back
            self.back=tmp
    
import sys
n,m,y,x,k=map(int,input().split())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
cmds=[*map(int,sys.stdin.readline().split())]
dy=[0,0,-1,1]
dx=[1,-1,0,0]
d1=dice()
for cmd in cmds:
    ny,nx=y+dy[cmd-1],x+dx[cmd-1]
    if(0<=ny<n and 0<=nx<m):
        d1.rotate(cmd)
        if(mat[ny][nx]==0):
            mat[ny][nx]=d1.down
        else:
            d1.down=mat[ny][nx]
            mat[ny][nx]=0
        sys.stdout.write(f'{d1.up}\n')
        y,x=ny,nx