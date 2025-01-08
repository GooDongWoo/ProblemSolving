import sys
input = sys.stdin.readline

n = int(input())
names = [input().rstrip() for _ in range(n)]
s1 = set()
for i in range(n):
    for j in range(n):
        if i == j: continue
        for k in range(1, len(names[j]) + 1):
            if k > len(names[i]): break
            if names[i][-k:] == names[j][:k]:
                s1.add((min(i,j),max(i,j)))
                break
print(len(s1))