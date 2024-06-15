from collections import deque
import heapq
n_test=int(input())


for _ in range(n_test):
    deq1=deque(list(input())) # make stack problem
    deq2=deque()
    try:
        while(deq1 or deq2):
            if(not deq1):
                break
            deq2.append(deq1.pop())
            while ( ((deq1[-1]=="(") and (deq2[-1]==")"))):
                deq1.pop()
                deq2.pop()
                if((not deq1) or (not deq2)):
                    break
            
        if(not(deq1 or deq2)):
            print("YES")
        else:
            print("NO")
    except:
        print("NO")