test_case=int(input())
for _ in range(test_case):
    x1,y1,x2,y2=map(int,input().split())
    n=int(input())
    planets=[]
    for i in range(n):
        planets.append((tuple(map(int,input().split()))))
    start=set()
    end=set()
    for area in planets:
        #start point
        if((((area[0]-x1)**2)+((area[1]-y1)**2))**(1/2)<=area[2]):#내부
            start.add(area)
        #end point
        if((((area[0]-x2)**2)+((area[1]-y2)**2))**(1/2)<=area[2]):#내부
            end.add(area)
    print(len(start^end))