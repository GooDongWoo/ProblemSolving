from collections import deque
import sys
input=sys.stdin.readline
print=sys.stdout.write

n_test=int(input())
deq=deque()
for _ in range(n_test):
    tmp_input = list(input().split())
    if(len(tmp_input)>1):
        tmp_input[1]=int(tmp_input[1])
        if(tmp_input[0]=='push_front'):
            deq.appendleft(tmp_input[1])
        elif (tmp_input[0]=='push_back'):
            deq.append(tmp_input[1])
    else:
        if (tmp_input[0]=='pop_front'):
            try:
                print(f'{deq.popleft()}\n')
            except:
                print(f'-1\n')
        elif (tmp_input[0]=='pop_back'):
            try:
                print(f'{deq.pop()}\n')
            except:
                print('-1\n')
        elif (tmp_input[0]=='size'):
            print(f'{len(deq)}\n')
        elif (tmp_input[0]=='empty'):
            tmp= 1 if not deq else 0 
            print(f'{tmp}\n')
        elif (tmp_input[0]=='front'):
            try:
                print(f'{deq[0]}\n')
            except:
                print('-1\n')
        elif (tmp_input[0]=='back'):
            try:
                print(f'{deq[-1]}\n')
            except:
                print('-1\n')  