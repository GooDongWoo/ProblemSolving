a=[0]*3
for i in range(3):
    a[i]=int(input())

product=a[0]*a[1]*a[2]
product=list(str(product))
cnt=[0]*10
for i in range(len(product)):
    cnt[int(product[i])]+=1
    
for i in range(10):
    print(cnt[i])