n = int(input())
a = [*map(int, input().split())]
b = [*map(int, input().split())]
print(sum(a))
t = sum([y * x for y, x in zip(a, b)])
print(sum(a) -  t)