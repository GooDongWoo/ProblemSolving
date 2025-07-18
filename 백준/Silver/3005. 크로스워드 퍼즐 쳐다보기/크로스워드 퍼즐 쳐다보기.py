import sys
input = sys.stdin.readline
R,C = map(int, input().split())
mat = [input().rstrip()  for _ in range(R)]
cands = []
for i in range(R):
    tmp = mat[i].split("#")
    for item in tmp:
        if(len(item)>1):
            cands.append(item)

for i in range(C):
    tmp = ""
    for j in range(R):
        tmp += mat[j][i]
    tmp = tmp.split("#")
    for item in tmp:
        if(len(item)>1):
            cands.append(item)
print(sorted(cands)[0])