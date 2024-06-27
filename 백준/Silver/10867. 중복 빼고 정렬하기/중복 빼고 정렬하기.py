import sys
a=int(sys.stdin.readline())
list1=list(map(int,sys.stdin.readline().split()))
list2=sorted(list(set(list1)))
print(*list2)