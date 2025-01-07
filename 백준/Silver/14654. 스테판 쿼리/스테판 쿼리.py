import sys
input = sys.stdin.readline

def chck(a, b):# a: -1, b: 1, draw: 0
    if (a == b):return 0
    elif ((a==2 and b==1) or (a==3 and b==2) or (a==1 and b==3)):return -1
    else:return 1

#편의상 가위를 1, 바위를 2, 보를 3
n = int(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
winner = [0] * n

if chck(l1[0], l2[0]) == -1:winner[0] = 0
else:winner[0] = 1

if n == 1:print(1);exit()

for i in range(1, n):
    res = chck(l1[i], l2[i])
    if (res == -1):winner[i] = 0
    elif(res == 1):winner[i] = 1
    else:
        if winner[i-1] == 0:winner[i] = 1
        else:winner[i] = 0

ans = 0
cnter = 1
for i in range(1, n):
    if winner[i] == winner[i-1]:
        cnter +=1
    else:
        ans = max(ans, cnter)
        cnter = 1
ans = max(ans, cnter)
print(ans)