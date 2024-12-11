import sys
input = sys.stdin.readline
def F(a, b, op):
    if op == '+':
        return a+b
    elif op == '-':
        return a-b
    elif op == '*':
        return a*b
    elif op == '/':
        return -1*(abs(a)//abs(b)) if a*b < 0 else a//b

l1 = list(input().split())
l1[0] = int(l1[0]); l1[2] = int(l1[2]); l1[4] = int(l1[4])
a = F(F(l1[0], l1[2], l1[1]), l1[4], l1[3])
b = F(l1[0], F(l1[2], l1[4], l1[3]), l1[1])
print(min(a, b))
print(max(a, b))