a,b=input().split()
a='0b'+a
b='0b'+b
print(str(bin(eval(a)+eval(b)))[2:])
