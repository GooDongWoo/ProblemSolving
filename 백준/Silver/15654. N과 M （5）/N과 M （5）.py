import sys
sys.setrecursionlimit(10**9)
n,m=map(int,input().split())
num_list=sorted(list(map(int,input().split())))
ox_list=[-1]*m

def dfs(digit,ox_list):
    global n,m,num_list
    tmp=ox_list.copy()
    if(digit==m):
        for i in range(m):
            sys.stdout.write(f'{num_list[tmp[i]]} ')
        sys.stdout.write(f'\n')
    else:
        if(digit<m):#each node has n-child
            for i in range(n):
                tmp[digit]=i
                if len(set(tmp[:digit+1]))==(digit+1):
                    dfs(digit+1,tmp)

dfs(0,ox_list)