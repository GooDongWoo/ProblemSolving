import sys
from collections import deque

while (1):
    sentence_input=sys.stdin.readline()
    stck1=deque()
    stck2=deque()
    if(sentence_input=='.\n'):
        break
    for each_char in sentence_input:
        if each_char =="(":
            stck1.append("(")
        elif each_char ==")":
            stck1.append(")")
        elif each_char =="[":
            stck1.append("[")
        elif each_char =="]":
            stck1.append("]")
        else:
            continue
    
    while(stck1):
        stck2.append(stck1.pop())
        while (stck1) and (stck2) and ((stck1[-1]=="(" and stck2[-1]==")") or (stck1[-1]=="[" and stck2[-1]=="]")):
            stck1.pop()
            stck2.pop()
    
    if(stck1 or stck2):
        sys.stdout.write(f'no\n')
    else:
        sys.stdout.write(f'yes\n')