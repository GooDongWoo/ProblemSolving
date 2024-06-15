n=int(input())
init=1
if(n>1):
    for i in range(2,n+1):
        init*=i
print(init)