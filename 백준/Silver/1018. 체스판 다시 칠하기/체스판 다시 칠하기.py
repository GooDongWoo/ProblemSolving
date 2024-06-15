h,w= map(int,input().split())

backboard=[list(input()) for _ in range(h)]
for i in range(h):
    for j in range(w):
        backboard[i][j]=1 if backboard[i][j]=="W" else 0

white_line=[(i+1)%2 for i in range(8)] 
black_line=[(i)%2 for i in range(8)]
white_corner=[0]*8
black_corner=[0]*8
for i in range(4):
    white_corner[2*i]=white_line.copy()
    white_corner[2*i+1]=black_line.copy()
    black_corner[2*i]=black_line.copy()
    black_corner[2*i+1]=white_line.copy()

minimal_num=h*w
tmp_w=0
tmp_b=0
for i in range(h-7):
    for j in range(w-7):
        for row in range(8):
            for col in range(8):
                if(backboard[row+i][col+j]!=black_corner[row][col]):
                    tmp_b+=1
                if(backboard[row+i][col+j]!=white_corner[row][col]):
                    tmp_w+=1
        minimal_num=min([minimal_num,tmp_b,tmp_w])
        tmp_w,tmp_b=(0,0)
print(minimal_num)