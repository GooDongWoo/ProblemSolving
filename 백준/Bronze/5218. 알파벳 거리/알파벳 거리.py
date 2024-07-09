n=int(input())
for _ in range(n):
    a,b=input().split()
    print("Distances: ",end='')
    for i in range(len(a)):
        if(ord(b[i])>=ord(a[i])):
            print(ord(b[i])-ord(a[i]),end=' ')
        else:
            print(ord(b[i])-ord(a[i]) +26,end=' ')
    print()