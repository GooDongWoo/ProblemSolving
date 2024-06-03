import sys
n=int(input())
str_list=[0]*n
for i in range(n):
    str_list[i]=sys.stdin.readline()

res=str_list[0]
for idx in range(len(str_list[0])):
    char1=str_list[0][idx]
    for row in range(len(str_list)):
        if(char1!=str_list[row][idx]):
            res=res[:idx]+'?'+res[idx+1:]
            break

print(res)