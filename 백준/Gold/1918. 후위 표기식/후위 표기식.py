import sys
from collections import deque
input=sys.stdin.readline

word=deque(list(input().rstrip()))
def solve(itr):
    optr_list=['+','-','*','/']
    pm_list=['+','-']
    mul_list=['*','/']
    
    opnd_stck=deque()
    optr_stck=deque()
    while itr:
        c=itr.popleft()
        if c in optr_list:optr_stck.append(c)
        else: 
            opnd_stck.append(c)
            if len(opnd_stck)>1 and len(optr_stck)>0:
                while optr_stck and itr and (optr_stck[-1] in pm_list) and (itr[0] in mul_list):
                    optr_stck.append(itr.popleft())
                    opnd_stck.append(itr.popleft())
                    opnd2=opnd_stck.pop()
                    opnd1=opnd_stck.pop()
                    optr=optr_stck.pop()
                    res=opnd1+opnd2+optr
                    opnd_stck.append(res)
                    
                opnd2=opnd_stck.pop()
                opnd1=opnd_stck.pop()
                optr=optr_stck.pop()
                res=opnd1+opnd2+optr
                opnd_stck.append(res)
    return opnd_stck.pop()
stck=deque()
tmp=deque()
while word:
    c=word.popleft()
    if c==')':
        while stck and stck[-1]!='(':
            tmp.appendleft(stck.pop())
        stck.pop()
        res=solve(tmp)
        stck.append(res)
        tmp=deque()
    else:stck.append(c)
print(solve(stck))