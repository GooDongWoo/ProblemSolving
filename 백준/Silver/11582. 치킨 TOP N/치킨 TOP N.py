n=int(input())
seq=[*map(int,input().split())]
k=int(input())
for i in range(0,n,n//k):
    seq[i:i+n//k]=sorted(seq[i:i+n//k])
print(*seq)