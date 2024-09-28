n=int(input())
origin=n
idx=0
while 1:
    n='0'+str(n) if(int(n)<10) else str(n)
    sum_n=str(sum([int(i) for i in n]))[-1]
    new_n=n[-1]+sum_n
    n=new_n
    idx+=1
    if(int(n)==origin):
        print(idx)
        break