import sys
n,m=map(int,input().split())
list1=sorted(list(map(int,sys.stdin.readline().split())))
idx_list=[-1]*m
idx_ox_set=set()
result_list=set()

#digit:digit자리의 숫자를 가르킬 idx/ 0~last,-> for state
#digit:0~last,-> for state
def dfs(digit,idx_list):
    global n,m,list1,result_list,idx_ox_set
    tmp=idx_list.copy()
    if(tmp[-1]!=-1):
        tmp_res=[]
        for i in range(m):
            tmp_res.append(str(list1[tmp[i]]))
        if tuple(tmp_res) not in result_list:
            result_list.add(tuple(tmp_res))
            sys.stdout.write(f'{" ".join(tuple(tmp_res))}\n')
    else:
        if(digit<n):
            for i in range(len(list1)):
                if i not in idx_ox_set:
                    tmp[digit]=i
                    idx_ox_set.add(i)
                    dfs(digit+1,tmp)
                    idx_ox_set.discard(i)

dfs(0,idx_list)  