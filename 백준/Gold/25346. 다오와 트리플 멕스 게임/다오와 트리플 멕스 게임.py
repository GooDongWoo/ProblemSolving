_ = int(input())
l = sorted(list(set(map(int,input().split()))))
N = len(l)
start = 0
for i in range(N):
    if(start != l[i]):
        break
    start += 1
if(start == 0):
    print(0)
elif(start==1 and N==1):
    print(1)
else:
    print(start+2)
'''
b -> c -> mex(c)
0 -> 1 -> 0
1 -> 0 -> 1
0,1 -> 0,1,2 -> 0,1,2,3
'''