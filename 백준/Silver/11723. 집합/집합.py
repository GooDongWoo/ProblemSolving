import sys
print=sys.stdout.write
input=sys.stdin.readline

n_test=int(input())
s=set()

def add(x):
    global s
    s|=set([x])
    return

def remove(x):
    global s
    s-=set([x])
    return

def check(x):
    global s
    if(x in s):
        print(f'1\n')
    else:
        print(f'0\n')
    return

def toggle(x):
    global s
    if(x in s):
        s-=set([x])
    else:
        s|=set([x])
    return

def all():
    global s
    s=set([i for i in range(1,21)])
    return

def empty():
    global s
    s=set()
    return

for _ in range(n_test):
    tmp=list(input().split())
    if len(tmp)==2:
        operator, operand=tmp[0],tmp[1]
        operand=int(operand)
        if(operator=="add"):
            add(operand)
        elif(operator=="remove"):
            remove(operand)
        elif(operator=="check"):
            check(operand)
        elif(operator=="toggle"):
            toggle(operand)
        
    else:
        operator=tmp[0]
        if(operator=="all"):
            all()
        elif(operator=="empty"):
            empty()
        