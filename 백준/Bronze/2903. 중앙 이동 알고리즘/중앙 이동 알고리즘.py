import sys
input=sys.stdin.readline

n = int(input())

w=[0]*16
w[0]=2
for i in range(1,16):
    w[i]=2*w[i-1]-1
print(w[n]**2)
