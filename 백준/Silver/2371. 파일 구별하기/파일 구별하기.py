import sys
input=sys.stdin.readline
n=int(input())
words=[list(input().split())[:-1] for _ in range(n)]
max_len=max([len(i) for i in words])
nm=[['0']*max_len for _ in range(n)]
for i in range(n):
    for j in range(len(words[i])):
        nm[i][j]=words[i][j]

for i in range(1,max_len+1):
    t_set=set()
    for j in range(n):
        t_set.add('.'.join(nm[j][0:i]))
    
    if(len(t_set)==n):
        print(i)
        break