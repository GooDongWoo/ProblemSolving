n=int(input())
cnt=0
a=[pow(5,i) for i in range(1,4)]
for i in range(3):
    cnt+=n//a[i]
print(cnt)