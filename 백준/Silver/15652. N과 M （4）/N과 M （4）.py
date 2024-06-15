import sys
n,m=map(int,input().split())
list1=[i for i in range(1,n+1)]
ox_list=[0]*n

def dfs(digit,ox_list):
    global n,m,list1
    tmp=ox_list.copy()
    if(sum(tmp)==m):
        for i in range(n):
            t1=ox_list[i]
            while(t1>0):
                sys.stdout.write(f'{list1[i]} ')
                t1-=1
        sys.stdout.write(f'\n')
    else:
        if(digit<n):
            tmp[digit]+=1
            dfs(digit,tmp)
            tmp[digit]-=1
            ####################################
            dfs(digit+1,tmp)
dfs(0,ox_list)