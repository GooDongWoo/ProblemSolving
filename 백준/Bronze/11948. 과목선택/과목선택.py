a = [int(input()) for _ in range(4)]
b = [int(input()) for _ in range(2)]
tot = sum(a) + sum(b) - min(a) - min(b)
print(tot)
