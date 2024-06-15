import sys
blue_paper=0
white_paper=0

def checkAllSame(n,dx,dy):
    global blue_paper, white_paper, square_mat
    cnt=0
    for i in range(n):
        for j in range(n):
            cnt+=square_mat[dy+i][dx+j]
    if(cnt==(n**2)):
        blue_paper+=1
        return 1
    if(cnt==0):
        white_paper+=1
        return 1
    return 0
def biSquare(n,dx,dy):
    global square_mat
    new_n=n//2
    
    if not (checkAllSame(new_n,dx,dy)):
        biSquare(new_n,dx,dy)
    
    if not (checkAllSame(new_n,dx+new_n,dy)):
        biSquare(new_n,dx+new_n,dy)
    
    
    if not (checkAllSame(new_n,dx,dy+new_n)):
        biSquare(new_n,dx,dy+new_n)

    
    if not (checkAllSame(new_n,dx+new_n,dy+new_n)):
        biSquare(new_n,dx+new_n,dy+new_n)

n=int(input())
square_mat=[0 for _ in range(n)]
for i in range(n):
    square_mat[i]=list(map(int,sys.stdin.readline().split()))
if not (checkAllSame(n,0,0)):
    biSquare(n,0,0)
print(white_paper)
print(blue_paper)