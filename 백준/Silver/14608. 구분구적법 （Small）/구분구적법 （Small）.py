import sys
radix=int(input())
coefficients=list(map(int,sys.stdin.readline().split()))[::-1]
a,b,n=map(int,sys.stdin.readline().split())

approxi=0
epsilon=0
for k in range(0,n):
    approxi+=coefficients[0]
    for rad in range(1,radix+1):
        approxi+=coefficients[rad]*(a+(k*(b-a)/n))*((b-a)/n)
        epsilon+=coefficients[rad]*((b-a)/n)

real=0
for rad in range(radix+1):
    real+=coefficients[rad]*(((b**(rad+1))-(a**(rad+1)))/(rad+1))

ans=(real-approxi)/epsilon
print(ans)