import sys
input = sys.stdin.readline

from collections import deque
word = list(input().rstrip())
q = deque()
for i in range(len(word)):
    if (word[i] != '?'): q.append(word[i])

nq = deque()
while q:
    cur = ""
    if q[0].isdigit():
        while q and q[0].isdigit(): 
            cur += q.popleft()
        nq.append(int(cur))
    else:
        nq.append(q.popleft())

def F1(q):
    tmp = deque()
    while q:
        if (type(q[0]) == int):
            tmp.append(q.popleft())
        else:
            if (q[0] in ['+', '-']):
                tmp.append(q.popleft())
            else:
                if (q[0] == '>'):
                    q.popleft()
                    first = tmp.pop()
                    second = q.popleft()
                    tmp.append(max(first, second))
                else:
                    q.popleft()
                    first = tmp.pop()
                    second = q.popleft()
                    tmp.append(min(first, second))
    res = tmp.popleft()
    while tmp:
        if (tmp[0] == '+'):
            tmp.popleft()
            res += tmp.popleft()
        else:
            tmp.popleft()
            res -= tmp.popleft()
    return res

def F2(q2):
    q1 = deque()
    while q2:
        if ((type(q2[0]) == int) or q2[0] != '('):
            q1.append(q2.popleft())
        else:
            optr = q2.popleft()
            if (optr == '('):
                nq = deque()
                open_bracket_cnt = 1
                close_bracket_cnt = 0
                while open_bracket_cnt != close_bracket_cnt:
                    tmp = q2.popleft()
                    if (tmp == '('): open_bracket_cnt += 1
                    elif (tmp == ')'): 
                        close_bracket_cnt += 1
                        if (open_bracket_cnt == close_bracket_cnt):break
                    nq.append(tmp)
                q1.append(F2(nq))
    return F1(q1)

print(F2(nq))