n,a,b=map(int,input().split())
a-=1
b-=1
rounds=1
while True:
    if (a)//2==(b)//2:
        print(rounds)
        break
    a//=2
    b//=2
    rounds+=1