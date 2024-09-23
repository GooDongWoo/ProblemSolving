n=int(input())
olds=[*map(int,input().split())]
news=sorted([(olds[i],i) for i in range(n)])
result=[0]*n
for i in range(n):
    result[news[i][1]]=i
print(*result)