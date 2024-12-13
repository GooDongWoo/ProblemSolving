for _ in range(3):
    a, b, c, d, e, f = map(int, input().split())
    res = [0] * 3
    if f >= c:
        res[2] = f - c
    else:
        e -= 1
        res[2] = 60 + f - c
    
    if e >= b:
        res[1] = e - b
    else:
        d -= 1
        res[1] = 60 + e - b
    res[0] = d - a
    print(*res)
    