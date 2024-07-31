n=int(input())
a=[*map(int,input().split())]
optr=[*map(int,input().split())]    # +,-,X,/
optr_res=[0]*(n-1)
candidates=[]

def f(a,b,cmd):
    if(cmd==0):
        return a+b
    elif(cmd==1):
        return a-b
    elif(cmd==2):
        return a*b
    else:
        if a<0:
            return -((-a)//b)
        else:
            return a//b

def bt(idx=0):
    global n,a,optr,optr_res
    # 만약 idx가 n-1이면 다 찼다는 것이니 그때 모든 연산자들로 계산하기
    if(idx==n-2):
        for tmp,left in enumerate(optr):
            if(left!=0):
                optr_res[idx]=tmp
        #찾았으니 모든 연산자들로 계산하기
        #print(optr_res) #for debugging
        res=a[0]
        for i in range(n-1):
            res=f(res,a[i+1],optr_res[i])
        candidates.append(res)
    # 만약 아니면 포문을 통해서 순서대로 체크하고 연산자들의 남은 개수가 있는지 확인하고 들어가기,들어갈때 연산자 개수 마이너스 
    else:
        for tmp,left in enumerate(optr):
            if(left!=0):
                optr[tmp]-=1
                optr_res[idx]=tmp
                bt(idx+1)
                #들어가고 나오면 연산자 개수 플러스
                optr[tmp]+=1

bt(0)
print(max(candidates))
print(min(candidates))