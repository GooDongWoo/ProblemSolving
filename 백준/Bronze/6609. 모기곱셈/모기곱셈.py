import sys
try:
    while 1:
        m,p,l,e,r,s,n=map(int,sys.stdin.readline().split())
        for _ in range(n):
            m,p,l=p//s,l//r,e*m
        print(m)
except:
    pass