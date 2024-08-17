a=int(input())
div=a//5
mod=a%5
tmp=div if mod==0 else div+1
print(tmp)