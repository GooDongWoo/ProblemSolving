import sys
n=int(sys.stdin.readline())
ps=list(map(float,sys.stdin.readline().split()))
nps=[1-i for i in ps]
sub_lamp_ps=[ps[i]*(1-ps[i+1])+ps[i+1]*(1-ps[i]) for i in range(n-1)]
print(sum(ps)+sum(sub_lamp_ps))