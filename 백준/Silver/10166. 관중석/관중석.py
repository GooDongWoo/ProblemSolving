import sys
d1,d2=map(int,sys.stdin.readline().split())
occupied=set()
for nth in range(d1,d2+1):
    step=360/nth
    mul=0
    while step*mul<360:
        occupied.add(step*mul)
        mul+=1
print(len(occupied))