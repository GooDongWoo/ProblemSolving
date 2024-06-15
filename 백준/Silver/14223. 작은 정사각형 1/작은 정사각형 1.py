import sys
n=int(sys.stdin.readline())
dot_list=[]
for _ in range(n):
    dot_list.append(list(map(int,sys.stdin.readline().split())))
area=int(1e20)
for i in range(n-1):
    for j in range(i+1,n):
        new_dot_list=dot_list.copy()
        new_dot_list=new_dot_list[:i]+new_dot_list[i+1:j]+new_dot_list[j+1:]
        max_x=-int(1e10)
        min_x=int(1e10)
        max_y=-int(1e10)
        min_y=int(1e10)
        for k in range(len(new_dot_list)):
            if(new_dot_list[k][0]>max_x):
                max_x=new_dot_list[k][0]
            if(new_dot_list[k][1]>max_y):
                max_y=new_dot_list[k][1]
            if(new_dot_list[k][0]<min_x):
                min_x=new_dot_list[k][0]
            if(new_dot_list[k][1]<min_y):
                min_y=new_dot_list[k][1]
        max1line=max((max_x-min_x+2),(max_y-min_y+2))
        area=min(area,max1line**2)
sys.stdout.write(f'{area}\n')