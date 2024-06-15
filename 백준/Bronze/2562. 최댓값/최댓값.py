import sys
num=[]
for i in range(9):
    num.append(int(sys.stdin.readline()))

max=1
idx=0
for i in range(9):
    if num[i] >max:
        max=num[i]
        idx=i
print(f'{max}')
print(f'{idx+1}')