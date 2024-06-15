import sys
n,m=map(int,input().split())
a=set()
b=set()
for _ in range(n):
    a.add(sys.stdin.readline().rstrip())
for _ in range(m):
    b.add(sys.stdin.readline().rstrip())

result=sorted(list(a.intersection(b)))
print(len(result))
for item in result:
    print(item)