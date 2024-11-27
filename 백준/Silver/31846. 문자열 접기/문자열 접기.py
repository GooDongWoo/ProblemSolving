import sys
input=sys.stdin.readline

n = int(input())
word = input().rstrip()
q = int(input())
for _ in range(q):
    a, b = map(int, input().split())
    a -= 1; b -= 1
    nw = word[a : b + 1]
    ans = 0
    for cut in range(1,len(nw)):
        can = 0
        w1 = nw[:cut][::-1]
        w2 = nw[cut:]
        min_len = min(len(w1), len(w2))
        for i in range(min_len):
            if (w1[i] == w2[i]): can += 1
        ans = max(ans, can)
    print(ans)