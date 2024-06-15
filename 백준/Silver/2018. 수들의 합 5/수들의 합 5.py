a= int(input())

i=0
j=0
mid=a//2+1
target=0
cnt=1
if a!=1 and a!=2:
    while j<= mid:
        target= j*(j+1)/2 - i*(i+1)/2
        
        if target==a:
            cnt+=1
            j+=1
        elif target < a:
            j+=1
        else:
            i+=1    
else:
    pass

        
print(cnt)