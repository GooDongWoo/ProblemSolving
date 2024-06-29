import sys
list1=[]
for i in range(3):
    list1.append(tuple(map(int,sys.stdin.readline().split())))
list1.sort(key=lambda x:x[0])
t_x=0
t_y=0
if(list1[0][0]==list1[1][0]):
    t_y=list1[2][0]
else:
    t_y=list1[0][0]
list1.sort(key=lambda x:x[1])
if(list1[0][1]==list1[1][1]):
    t_x=list1[2][1]
else:
    t_x=list1[0][1]
print(t_y,t_x)