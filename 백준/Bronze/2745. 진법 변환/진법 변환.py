import sys
input=sys.stdin.readline

num,base=input().split()
base=int(base)

print(int(num,base))