x, y = map(int, input().split())

if x > y:
    for i in range(1, y + 1):
        print(f"0:{i}")
    for i in range(1, x + 1):
        print(f"{i}:{y}")
else:
    for i in range(1, x + 1):
        print(f"{i}:0")
    for i in range(1, y + 1):
        print(f"{x}:{i}")