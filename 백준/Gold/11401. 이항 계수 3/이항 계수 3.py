n,k=map(int,input().split())
MOD=int(1e9)+7
fact=[1,1]
for i in range(2,n+1):
    fact.append(fact[-1]*i % MOD)

factinv=[]
for i in range(len(fact)):
    factinv.append(pow(fact[i],-1,MOD))

result=fact[n]*factinv[n-k]*factinv[k]%MOD
print(result)