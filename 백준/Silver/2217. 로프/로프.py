import sys
n=int(sys.stdin.readline())
ropes=[int(sys.stdin.readline()) for _ in range(n)]
ropes.sort()
c=[0]*n
c[0]=(n)*(ropes[0])
for i in range(1,n):
    c[i]=(n-i)*(ropes[i])
print(max(c))