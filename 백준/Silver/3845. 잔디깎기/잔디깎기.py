while 1:
    _,_,w=map(float,input().split())
    if(w==0):break
    xs=sorted([*map(float,input().split())])
    ys=sorted([*map(float,input().split())])
    F=0
    
    clean_x=[0,0]
    for x in xs:#0~75
        l,r=x-w/2, x+w/2
        if(l<=clean_x[1]):
            clean_x[0],clean_x[1]=l,r
        else:
            F=1
            break
    if(clean_x[1]<75):F=1
    
    clean_y=[0,0]
    for y in ys:#0~100
        l,r=y-w/2, y+w/2
        if(l<=clean_y[1]):
            clean_y[0],clean_y[1]=l,r
        else:
            F=1
            break
    if(clean_y[1]<100):F=1
    if(F):
        print('NO')
    else:
        print('YES')