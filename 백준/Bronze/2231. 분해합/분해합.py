n=input()
len_n=len(n)
n=int(n)
flag=0
if(len_n-2<0):
    for i in range(1,n):
        tmp_i=str(i)
        sum_tmp=0
        for item in tmp_i:
            sum_tmp+=int(item)
        result=sum_tmp + i
        if(result==n):
            print(i)
            flag=1
            break
else:
    for i in range(pow(10,len_n-2),n):
        tmp_i=str(i)
        sum_tmp=0
        for item in tmp_i:
            sum_tmp+=int(item)
        result=sum_tmp + i
        if(result==n):
            print(i)
            flag=1
            break
if not(flag):
    print(0)
    
    
    
    
    
    