import sys
n=int(sys.stdin.readline())
hose_list=list((map(int,sys.stdin.readline().split())))
toggle=set([i for i in range(n)])
m=int(sys.stdin.readline())
w_amnt=sum(hose_list)
sys.stdout.write(f'{w_amnt}\n')
for _ in range(m):
    tmp=list(map(int,sys.stdin.readline().split()))
    if(tmp[0]==1):#manipulate
        if((tmp[1]-1) in toggle):
            w_amnt-=hose_list[tmp[1]-1]
            hose_list[tmp[1]-1]=tmp[2]
            w_amnt+=hose_list[tmp[1]-1]
        else:
            hose_list[tmp[1]-1]=tmp[2]
            
    else:#toggle
        if((tmp[1]-1) in toggle): #잇으면 틀어놓고 잇던거 이제 잠가야지
            toggle.discard(tmp[1]-1)
            w_amnt-=hose_list[tmp[1]-1]
        else:#이제 틀어놓아야지
            toggle.add(tmp[1]-1)
            w_amnt+=hose_list[tmp[1]-1]
    sys.stdout.write(f'{w_amnt}\n')