import sys
input = sys.stdin.readline

from collections import deque

n = int(input())

last = []
word = deque()
for _ in range(n):
    tmp = input().rstrip()
    if tmp[0] != '3':
        a, b = tmp.split()
        if a == '1':
            word.append(b)
            last.append(-1)
        else:
            word.appendleft(b)
            last.append(0)
    else:
        if len(word):
            if last.pop() == 0:
                word.popleft()
            else:
                word.pop()
if word:
    print(''.join(list(word)))
else:
    print(0)