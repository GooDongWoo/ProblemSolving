while 1:
    n=int(input())
    if n==-1:break
    tmp=[]
    for i in range(1,n):
        if n%i==0:
            tmp.append(i)
    if sum(tmp)==n: 
        print(n,'=',end=' ')
        print(*tmp,sep=' + ')
    else:
        print(f"{n} is NOT perfect.")