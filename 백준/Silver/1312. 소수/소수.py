import sys
A,B,N=map(int,input().split())

left=A%B
for i in range(1,N+1):
    tmp,left=((left)*10)//B,((left)*10)%B
    
print(tmp)