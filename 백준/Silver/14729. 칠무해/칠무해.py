import sys
n=int(sys.stdin.readline())
list1=[float(sys.stdin.readline()) for _ in range(n)]
list1.sort()
for i in range(7):
    print(f'{list1[i]:.3f}')