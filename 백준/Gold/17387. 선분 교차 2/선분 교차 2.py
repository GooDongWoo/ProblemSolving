import sys
def main():
    x1,y1,x2,y2=map(int,sys.stdin.readline().split())
    tmp=sorted([(x1,y1),(x2,y2)],key=lambda x:(x[0],x[1]))
    x1,y1=tmp[0]
    x2,y2=tmp[1]
    
    x3,y3,x4,y4=map(int,sys.stdin.readline().split())
    tmp=sorted([(x3,y3),(x4,y4)],key=lambda x:(x[0],x[1]))
    x3,y3=tmp[0]
    x4,y4=tmp[1]

    v1=False
    v2=False
    if((x1-x2)):
        a1=(y1-y2)/(x1-x2)
        b1=y1-a1*x1    
    else:
        v1=True
    if((x3-x4)):
        a2=(y3-y4)/(x3-x4)
        b2=y3-a2*x3
    else:
        v2=True
    if(v1 and not v2):
        if(x3<=x1<=x4 and min(y1,y2)<=round(a2*x1+b2,9)<=max(y1,y2)):
            print(1)
            return
        else:
            print(0)
            return
    if(v2 and not v1):
        if(x1<=x3<=x2 and min(y3,y4)<=round(a1*x3+b1,9)<=max(y3,y4)):
            print(1)
            return
        else:
            print(0)
            return
    if(v1 and v2):
        if(x3==x1 and ((y3 <=y1 and y4>=y1) or (y3 >= y1 and y2 >=y3))):
            print(1)
            return
        else:
            print(0)
            return
    start=max(x1,x3)
    end=min(x2,x4)
    if(start<=end):
        if(round(a1*start+b1,9)==round(a2*start+b2,9) or round(a1*end+b1,9)==round(a2*end+b2,9)):
            print(1)
        else:
            if (bool((a1*start+b1)>=(a2*start+b2))^bool((a1*end+b1)>=(a2*end+b2))):
                print(1)
            else:
                print(0)
    else:
        print(0)
if __name__=='__main__':
    main()