import sys
n,m=map(int,input().split())
list1=[i for i in range(1,n+1)]
ox_list=[0]*n

def dfs(digit,ox_list):
    global n,m,list1
    tmp=ox_list.copy()
    if(sum(tmp)==m):
        for i in range(n):
            if(ox_list[i]==1):
                sys.stdout.write(f'{list1[i]} ')
        sys.stdout.write(f'\n')
    else:
        if(digit<n):
            tmp[digit]=1
            dfs(digit+1,tmp)
            tmp[digit]=0
            dfs(digit+1,tmp)

dfs(0,ox_list)