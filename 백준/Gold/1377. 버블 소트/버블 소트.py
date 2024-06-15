import sys
print=sys.stdout.write
input=sys.stdin.readline

list_size=int(input())
item_list=[]
for i in range(list_size):
    item_list.append(int(input()))

sorted_list=sorted(item_list)
idx_table1 = [0]*1000001
idx_table2 = [0]*1000001
for idx,i in enumerate(item_list):
    idx_table1[i]=idx

for idx,i in enumerate(sorted_list):
    idx_table2[i]=idx
    
tmp=1
for i in range(len(idx_table1)):
    tmp=max(tmp,idx_table1[i]-idx_table2[i]+1)
print(f'{tmp}')