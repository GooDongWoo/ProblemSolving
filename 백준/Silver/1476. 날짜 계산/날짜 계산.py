e, s, m = map(int, input().split())
mul = 0
while 1:
    target = mul * 28 + s
    if ((target - e) % 15 == 0) and ((target - m) % 19 == 0):
        print(target);exit();
    mul += 1