a=input().rstrip()
f='7' in a
s=int(a)%7==0
if(not f and not s):
    print(0)
elif(not f and s):
    print(1)
elif(f and not s):
    print(2)
else:
    print(3) 
    