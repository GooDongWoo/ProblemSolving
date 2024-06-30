import sys
list1=sorted(list(map(int,sys.stdin.readline().split())))
if(list1[0]+list1[1]>list1[2]):
    print(sum(list1))
else:
    print(list1[0]+list1[1]+list1[0]+list1[1]-1)