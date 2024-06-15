import sys
N=int(input())
item_list=[0]*N
hash_tbl=[0]*8001
for i in range(-4000,4001):
    hash_tbl[i+4000]=[i,0]
for i in range(N):
    tmp=int(sys.stdin.readline())
    item_list[i]=tmp
    hash_tbl[tmp+4000][1]+=1
item_list.sort()
hash_tbl.sort(key=lambda x: x[1],reverse=True)

print(round(sum(item_list)/len(item_list)))
print(item_list[len(item_list)//2])
print(hash_tbl[0][0] if hash_tbl[0][1]!=hash_tbl[1][1] else hash_tbl[1][0])
print(item_list[-1]-item_list[0])