import math

N,r,c=map(int,input().split())
#가장 겉에 있는 영역에서 구한 다음 몇번 가 아래 영역에서 몇번 더한것인지 안다음 밑의 것 구현->재귀
def findZ(N,r,c):
    if(N==1):
        if(r==0 and c==0):
            return 0
        elif (r==0 and c==1):
            return 1
        elif (r==1 and c==0):
            return 2
        elif (r==1 and c==1):
            return 3
    
    step=(2**(N-1))**2
    r_flag=False
    c_flag=False
    if(r-(2**(N-1))>=0):
        r_flag=True
    if(c-(2**(N-1))>=0):
        c_flag=True
    
    if (not r_flag and c_flag):
        return (1*step)+findZ(N-1,r,c-(2**(N-1)))
    elif (r_flag and not c_flag):
        return (2*step)+findZ(N-1,r-(2**(N-1)),c)
    elif (r_flag and c_flag):
        return (3*step)+findZ(N-1,r-(2**(N-1)),c-(2**(N-1)))
    else:
        return findZ(N-1,r,c)

print(findZ(N,r,c))