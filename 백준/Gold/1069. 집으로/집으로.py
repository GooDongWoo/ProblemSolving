X,Y,D,T = map(int, input().split())
realLen = ((X**2) + (Y**2))**.5
if((D/T)<=1):
    print(realLen)
    exit()
div = realLen // D
if(div>0):
    print(min(abs(realLen - (div*D))+(T*div), (T*(div+1))))
else:
    print(min(realLen, min(abs(realLen-D)+T,T*2)))