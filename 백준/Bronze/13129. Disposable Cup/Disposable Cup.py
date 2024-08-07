a,b,n=map(int,input().split())
up=set([a+b])
down=set([a+b])
for i in range(1,n):
    new_up=set([d+(a+b) for d in down])|set([u+(a) for u in up])
    new_down=set([d+(a) for d in down])|set([u+(a+b) for u in up])
    up=new_up
    down=new_down
result=sorted(list(up|down))
print(*result)