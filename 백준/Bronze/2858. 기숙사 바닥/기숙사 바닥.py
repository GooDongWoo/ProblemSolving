r, b =map(int, input().split())
for l in range(1, int((r + b) ** 0.5) + 1):
    if ((r + b) % l == 0):
        if (l + (r + b) // l == r // 2 + 2):
            w = (r + b) // l
            break
print(max(l, w), min(l, w))