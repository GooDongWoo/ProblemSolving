import sys
n=int(sys.stdin.readline())
origin=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]

cases=[]
tmp=[0]*5
def combis(idx):
    global cases,tmp
    if(idx==5):
        cases.append(tmp.copy())
    else:
        for i in range(4):
            tmp[idx]=i
            combis(idx+1)

def F(mat1): #swipe left
    tmp_mat=[]
    for row in mat1:
        row_not_zero=[]
        for i in row:
            if(i!=0):
                row_not_zero.append(i)#row_not_zero는 길이가 0일 수도 1일 수도 n개일 수도 있다.
        new_row=[]
        l1=len(row_not_zero)
        if(l1>1):#합쳐버리는 거 구현
            tdx=0
            while tdx<(l1-1):
                if(row_not_zero[tdx]==row_not_zero[tdx+1]):
                    new_row.append(row_not_zero[tdx]*2)
                    tdx+=2
                else:
                    new_row.append(row_not_zero[tdx])
                    tdx+=1
            if(tdx==l1-1):
                new_row.append(row_not_zero[tdx])
                tdx+=1
        elif(l1==1):
            new_row.append(row_not_zero[0])
        else:
            pass
        #이제 차원을 맞춰줘야함
        new_row+=[0]*(n-len(new_row))
        tmp_mat.append(new_row.copy())
    return tmp_mat

def swipeup():
    global mat
    nmat=[*zip(*mat)] #make mat by rows
    nmat=F(nmat)
    mat=[*zip(*nmat)]

def swipedown():
    global mat
    nmat=[*zip(*mat)]
    nmat=[vector[::-1] for vector in nmat]
    nmat=F(nmat)
    nmat=[vector[::-1] for vector in nmat]
    mat=[*zip(*nmat)]

def swipeleft():
    global mat
    mat=F(mat)

def swiperight():
    global mat
    nmat=[vector[::-1] for vector in mat]
    nmat=F(nmat)
    mat=[vector[::-1] for vector in nmat]

def swipe(case):
    if case==0:
        swipeup()
    elif case==1:
        swipedown()
    elif case==2:
        swipeleft()
    else:
        swiperight()

combis(0)
result=[]
for cmds in cases:
    mat=[i.copy() for i in origin]
    for cmd in cmds:
        swipe(cmd)
    max1=0
    for i in range(n):
        max1=max(max1,max(mat[i]))
    result.append(max1)
print(max(result))