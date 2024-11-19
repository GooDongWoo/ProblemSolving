import sys
input=sys.stdin.readline

INF=int(1e9)+7
m = int(input())
a = [list(map(int,input().split())) for _ in range(m)]
print(sum([s*pow(n,INF-2,INF) for n,s in a])%INF)
