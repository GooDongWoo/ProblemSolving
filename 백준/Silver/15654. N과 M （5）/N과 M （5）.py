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
#시간초과;; 개인적인 생각으로는 자식이 최대8개 생기고 depth가 8까지 가능하니 8^8은은 16,000,000인데;; 머지? 복잡도 제한 안에 들어와잇는거 같은데;; sort 때문인가? len 8짜리 해도 8*3=24 아님? 하;; 그래서 중복체크부터 sort 안쓰려고 set 사용하려고 함;;
'''
import sys
sys.setrecursionlimit(10**9)
n,m=map(int,input().split())
num_list=sorted(list(map(int,input().split())))
ox_list=[0]*m

def chckDupli(ox_list):
    tmp=sorted(ox_list)
    for i in range(1,len(tmp)):
        if((tmp[i]==tmp[i-1])):
            return True
    return False

def dfs(digit,ox_list):
    global n,m,num_list
    tmp=ox_list.copy()
    if(digit==m):
        if not (chckDupli(tmp)):
            for i in range(m):
                sys.stdout.write(f'{num_list[tmp[i]]} ')
            sys.stdout.write(f'\n')
    else:
        if(digit<m):#each node has n-child
            for i in range(n):
                tmp[digit]=i
                dfs(digit+1,tmp)

dfs(0,ox_list)
'''