n=int(input())
ropes=[int(input()) for _ in range(n)]
ropes.sort()
c=[0]*n
for i in range(n):
    c[i]=(n-i)*(ropes[i])
print(max(c))