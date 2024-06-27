import sys
total=6
a=int(sys.stdin.readline())
result=[]
def hanoi(n:int,start:int,end:int)->int:
    global total
    mid=total-start-end
    if(n==1):
        result.append((start,end))
    else:
        hanoi(n-1,start,mid)
        result.append((start,end))
        hanoi(n-1,mid,end)
hanoi(a,1,3)
sys.stdout.write(f'{len(result)}\n')
for i in range(len(result)):
    sys.stdout.write(f' '.join(map(str,result[i])))
    sys.stdout.write(f'\n')