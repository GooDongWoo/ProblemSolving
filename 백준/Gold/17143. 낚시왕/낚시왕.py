import sys
class shark():
    dir_dict={1:(-1,0), 2:(1,0),3:(0,1),4:(0,-1)}
    def __init__(self,r,c,s,d,z,name) -> None:
        self.r=r
        self.c=c
        self.s=s
        self.d=d
        self.z=z
        self.name=name
        sea[r][c]=self

    def move(self):
        dy,dx=self.dir_dict[self.d]
        dy,dx=self.s*dy,self.s*dx
        if(dy):
            if(dy>0):
                dy=dy%(2*(R-1))
            else:
                dy=-((-dy)%(2*(R-1)))
            while dy:
                if(dy>0):
                    if(self.r+dy>R):
                        dy-=(R-self.r)
                        self.r=R
                        dy=-dy
                        self.d=1
                    else:
                        self.r+=dy
                        break
                else:
                    if(self.r+dy<1):
                        dy+=(self.r-1)
                        self.r=1
                        dy=-dy
                        self.d=2
                    else:
                        self.r+=dy
                        break
        else:#dx
            if(dx>0):
                dx=dx%(2*(C-1))
            else:
                dx=-((-dx)%(2*(C-1)))
            while dx:
                if(dx>0):
                    if(self.c+dx>C):
                        dx-=(C-self.c)
                        self.c=C
                        dx=-dx
                        self.d=4
                    else:
                        self.c+=dx
                        break
                else:
                    if(self.c+dx<1):
                        dx+=(self.c-1)
                        self.c=1
                        dx=-dx
                        self.d=3
                    else:
                        self.c+=dx
                        break
        if(sea[self.r][self.c]):
            if(sea[self.r][self.c].z>self.z):
                sharks[self.name]=None
            else:
                sharks[sea[self.r][self.c].name]=None
                sea[self.r][self.c]=self
        else:
            sea[self.r][self.c]=self

R,C,M=map(int,sys.stdin.readline().split())
sharks=[0]*M
sea=[[0 for _ in range(C+1)] for _ in range(R+1)]
tmp_sea=[[0 for _ in range(C+1)] for _ in range(R+1)]
for i in range(M):
    sharks[i]=shark(*(list(map(int,sys.stdin.readline().split()))+[i]))

cnter=0
for j in range(1,C+1):
    #낚시왕
    for k in range(1,R+1):
        if(sea[k][j]):
            cnter+=sea[k][j].z
            sharks[sea[k][j].name]=None
            break
    sea=[[0 for _ in range(C+1)] for _ in range(R+1)]
    #상어 이동
    for shark1 in sharks:
        if(shark1):
            shark1.move()
print(cnter)