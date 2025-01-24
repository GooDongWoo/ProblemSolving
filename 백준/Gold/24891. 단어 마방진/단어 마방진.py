import sys
input = sys.stdin.readline
 
l, n = map(int, input().split())
words = sorted([input().rstrip() for _ in range(n)])
v = [0]* n

ans = []
tmp = []
def bt():
    global ans, tmp
    if (len(tmp) == l):
        ans.append(tmp.copy())
    else:
        for i in range(n):
            if v[i]: continue
            v[i] = 1
            tmp.append(words[i])
            tl = len(tmp)
            flag = 1
            for j in range(tl):
                if (tmp[-1][j] != tmp[j][tl-1]):flag = 0;break
            if (flag): 
                bt()
                tmp.pop()
                v[i] = 0
            else:
                tmp.pop()
                v[i] = 0
            
bt()
if len(ans):print(*ans[0],sep='\n')
else:print("NONE")