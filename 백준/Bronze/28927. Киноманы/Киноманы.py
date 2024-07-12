a=[*map(int,input().split())]
b=[*map(int,input().split())]
a_=a[0]*3+a[1]*20+a[2]*120
b_=b[0]*3+b[1]*20+b[2]*120
if(a_>b_):
    print('Max')
elif(a_<b_):
    print('Mel')
else:
    print('Draw')
    