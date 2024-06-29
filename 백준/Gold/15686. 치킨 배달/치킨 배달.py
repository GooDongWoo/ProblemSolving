import sys
def combination(total_list,n):
    result=[]
    tmp=[]
    def recursive(idx,n):
        if (len(tmp)==n):
            result.append(tmp.copy())
            return 1
        for i in range(idx,len(total_list)):
            tmp.append(total_list[i])
            recursive(i+1,n)
            tmp.pop()
    recursive(0,n)
    return result
n,m=map(int,sys.stdin.readline().split())
chick_mat=[[0 for _ in range(n)] for _ in range(n)]
house_list=[]
chick_list=[]
inf=int(1e8)
for i in range(n):
    chick_mat[i]=list(map(int,sys.stdin.readline().split()))
    for j in range(n):
        if(chick_mat[i][j]==1):
            house_list.append((i,j))
        elif(chick_mat[i][j]==2):
            chick_list.append((i,j))
result=inf
for picked_chicks in combination(chick_list,m):
    cost=[inf]*(len(house_list))
    for i in range(len(house_list)):
        for picked_chick in picked_chicks:
            cost[i]=min(cost[i],abs(house_list[i][0]-picked_chick[0])+abs(house_list[i][1]-picked_chick[1]))
    result=min(result,sum(cost))
print(result)