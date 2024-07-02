import sys
t=int(sys.stdin.readline())
for _ in range(t):
    a,b=map(int,sys.stdin.readline().split())
    print(int(((a+b)**2)*(a+b-1)/2))