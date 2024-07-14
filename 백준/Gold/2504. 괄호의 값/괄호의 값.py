import sys
from collections import deque
items=list(sys.stdin.readline().rstrip())
s=deque()
s.append(items[0])
for i in range(1,len(items)):
    
    if(len(s)>1 and type(s[-1])==int and type(s[-2])==int):
        t1=s.pop()
        t2=s.pop()
        s.append(t1+t2)
        
    s.append(items[i])
    
    if(len(s)>1 and s[-2]=='[' and s[-1]==']'):
        s.pop()
        s.pop()
        s.append(3)
    elif(len(s)>1 and s[-2]=='(' and s[-1]==')'):
        s.pop()
        s.pop()
        s.append(2)
    elif(len(s)>2 and type(s[-2])==int and s[-3]=='(' and s[-1]==')'):
        s.pop()
        t1=s.pop()
        s.pop()
        s.append(t1*2)
    elif(len(s)>2 and type(s[-2])==int and s[-3]=='[' and s[-1]==']'):
        s.pop()
        t1=s.pop()
        s.pop()
        s.append(t1*3)

if(len(s)>1 and type(s[-1])==int and type(s[-2])==int):
    t1=s.pop()
    t2=s.pop()
    s.append(t1+t2)
    
if(len(s)==1 and type(s[-1])==int):
    print(s[-1])
else:
    print(0)