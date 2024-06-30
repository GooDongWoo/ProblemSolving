import sys
while 1:
    list1=sorted(list(map(int,sys.stdin.readline().split())))
    if(sum(list1)==0):
        break
    if(list1[0]+list1[1]<=list1[2]):
        print('Invalid')
    elif(list1[0]==list1[1] and list1[1]==list1[2]):
        print('Equilateral')
    elif(list1[0]==list1[1] or list1[1]==list1[2] or list1[0]==list1[2]):
        print('Isosceles')
    else:
        print('Scalene')