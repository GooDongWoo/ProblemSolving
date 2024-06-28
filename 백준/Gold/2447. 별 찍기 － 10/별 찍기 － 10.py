import sys
n=int(sys.stdin.readline())
mat1=[[' ' for _ in range(n)] for _ in range(n)]
def insertStar(n,s_y,s_x):
    global mat1s
    if(n==3):
        mat1[s_y][s_x+0]='*'
        mat1[s_y][s_x+1]='*'
        mat1[s_y][s_x+2]='*'
        mat1[s_y+1][s_x+0]='*'
        # mat1[s_y+1][s_x+1]=' '
        mat1[s_y+1][s_x+2]='*'
        mat1[s_y+2][s_x+0]='*'
        mat1[s_y+2][s_x+1]='*'
        mat1[s_y+2][s_x+2]='*'
    else:
        insertStar(n//3,s_y,s_x)
        insertStar(n//3,s_y,s_x+n//3)
        insertStar(n//3,s_y,s_x+n*2//3)
        
        insertStar(n//3,s_y+n//3,s_x)
        #mat1[1][1]=bef_space
        insertStar(n//3,s_y+n//3,s_x+n*2//3)
        
        insertStar(n//3,s_y+n*2//3,s_x)
        insertStar(n//3,s_y+n*2//3,s_x+n//3)
        insertStar(n//3,s_y+n*2//3,s_x+n*2//3)

insertStar(n,0,0)

for i in range(len(mat1)):
    print("".join(mat1[i]))