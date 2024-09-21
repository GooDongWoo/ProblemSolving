import sys
lim=4*int(1e6)
MOD=int(1e9)+7
fact=[1]
for i in range(1,lim+1):
    fact.append(fact[-1]*i % MOD)

factinv=[]
for i in range(len(fact)):
    factinv.append(pow(fact[i],-1,MOD))

m=int(sys.stdin.readline())
for _ in range(m):
    n,k=map(int,sys.stdin.readline().split())
    result=fact[n]*factinv[n-k]*factinv[k]%MOD
    sys.stdout.write(f'{result}\n')