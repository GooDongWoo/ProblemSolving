import sys
from collections import deque
n=int(sys.stdin.readline())
methods=[*map(int,sys.stdin.readline().split())]
cards=deque()
for i in range(n):
    if(methods[n-1-i]==1):#제일 위에 올려 놓음
        cards.append(i+1)
        
    elif(methods[n-1-i]==2):#제일 위 팝하고 그위에다가 올리고 팝한 것을 다시 쌓음(2번째에 쌓는다는 말)
        tmp=cards.pop()
        cards.append(i+1)
        cards.append(tmp)
        
    else:#제일 아래에다가 넣는다.
        cards.appendleft(i+1)
sys.stdout.write(f'{" ".join([*map(str,reversed(list(cards)))])}')