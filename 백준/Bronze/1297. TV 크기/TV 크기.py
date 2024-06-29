import sys
d,h,w=map(int,sys.stdin.readline().split())
tmp=((d**2)/(h**2 + w**2))**(1/2)
print(int(tmp*h),int(tmp*w))