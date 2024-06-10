import sys
from collections import deque

test_case=int(input().rstrip())
def R():
    global reverse_flag
    reverse_flag= not(reverse_flag)
    return True

def D(deq1):
    global reverse_flag,err_flag
    if(deq1):
        if(reverse_flag):
            deq1.pop()
        else:
            deq1.popleft()
        return True
    else:
        err_flag=True
        return False
    
def runFunc(func,deq1):
    if func=='R':
        return R()
    else:
        return D(deq1)
    
for _ in range(test_case):
    optr_list=list(sys.stdin.readline().rstrip())
    len_list=int(sys.stdin.readline().rstrip())
    if(len_list and len_list!=1):
        item_list=list(sys.stdin.readline().strip()[1:-1].split(sep=','))
    elif(len_list==1):
        item_list=list(sys.stdin.readline().strip()[1])
    else:
        sys.stdin.readline()
        item_list=list()
    deq1=deque(item_list)
    reverse_flag=False
    err_flag=False
    for func1 in (optr_list):
        if(not runFunc(func1,deq1)):
            break
    if(not err_flag):
        sys.stdout.write('[')
        if(len(deq1)>1):
            if(reverse_flag):
                sys.stdout.write(','.join(list(deq1)[::-1]))
            else:
                sys.stdout.write(','.join(list(deq1)))
        elif(len(deq1)==1):
            sys.stdout.write(list(deq1)[0])
        else:
            pass
        sys.stdout.write(']\n')
    else:
        sys.stdout.write(f'error\n')