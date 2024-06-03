x=int(input())
if(x==1):
    print(f'1/1')
    pass
else:
    row,col=1,1
    cnt=1
    start_sum=2
    flag=1
    while(flag):
        for i in range(start_sum-2): #각 대각선의 칸 수
            #짝수는 대각선으로 올라가고 홀수는 내려간다.
            if(start_sum%2):#odd
                row+=1
                col-=1
            else:
                row-=1
                col+=1
            cnt+=1
            if(cnt==x):
                flag=0
                break
        if(not flag or cnt==x):
            flag=0
            break
        row+=start_sum%2
        col+=(start_sum+1)%2
        cnt+=1
        if(not flag or cnt==x):
            flag=0
            break
        start_sum+=1
    print(f'{row}/{col}')