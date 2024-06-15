import sys
from collections import deque
str_list=sys.stdin.readline().strip()
bomb_str=sys.stdin.readline().strip()

length_bomb=len(bomb_str)
first_bomb_char=bomb_str[0]
deq1=deque()
deq2=deque(list(str_list))

    
while(deq2):
    char1=deq2.popleft()
    deq1.append(char1)
    flag=0
    if(char1==first_bomb_char):
        if(len(deq2)<length_bomb-1):
            continue
        chck1=0
        for i in range(length_bomb-1):
            if(deq2):
                tmp_pop=deq2.popleft()
                deq1.append(tmp_pop)
                if(bomb_str[1+i]!=tmp_pop):
                    deq2.appendleft(deq1.pop())
                    flag=1
                    break
            else:
                break
        if not (flag):
            for _ in range(length_bomb):
                deq1.pop()
            for _ in range(length_bomb-1):
                if(deq1):
                    deq2.appendleft(deq1.pop())       
if(deq1): 
    print("".join((list(deq1))))
else:
    print('FRULA')