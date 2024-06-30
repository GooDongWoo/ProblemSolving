import sys
list1=[int(sys.stdin.readline()) for _ in range(3)]
if(sum(list1)!=180):
    print('Error')
else:
    if(list1[0]==60 and list1[1]==60 and list1[2]==60):
        print('Equilateral')
    elif(list1[0]==list1[1] or list1[1]==list1[2] or list1[0]==list1[2]):
        print('Isosceles')
    else:
        print('Scalene')