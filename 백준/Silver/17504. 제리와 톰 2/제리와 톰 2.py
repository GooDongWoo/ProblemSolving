import sys
input = sys.stdin.readline

from collections import deque

n = int(input())
l = deque(list(map(int, input().split())))

tmp = l.pop()
l.append((1, tmp))

def F(a, b): # b: (mul, div)
    mul = b[0]
    div = b[1]
    return (div, a * div + mul)

while len(l) != 1:
    s = l.pop()
    f = l.pop()
    l.append(F(f, s))

mul, div = l.pop()
print(div - mul, div)