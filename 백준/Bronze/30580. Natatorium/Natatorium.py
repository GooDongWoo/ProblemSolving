target = int(input())
num = int(input())
a = sorted(list(map(int, input().split())))
s1 = set(a)
for i in range(num):
    if(target % a[i] == 0 and ((target//a[i]) in s1)):
        print(a[i], target//a[i])
        break