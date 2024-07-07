t,w,h=map(int,input().split())
limit=((w*w)+(h*h))**(1/2)
for _ in range(t):
    tmp=int(input())
    if(tmp>limit):
        print('NE')
    else:
        print('DA')
        
    