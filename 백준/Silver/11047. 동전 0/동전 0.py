import sys
n,k=map(int,input().split())
coin_list=[int(sys.stdin.readline()) for _ in range(n)]

flag=-1
for i in range(len(coin_list)):
    if(coin_list[i]<=k):
        flag=i
    
num_coin=0    
left_k=k
for j in range(flag,-1,-1):
    while(left_k>=coin_list[j]):
        quotient=left_k//coin_list[j]
        left_k%=coin_list[j]
        num_coin+=quotient

print(num_coin)