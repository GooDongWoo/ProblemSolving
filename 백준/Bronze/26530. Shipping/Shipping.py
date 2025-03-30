n = int(input())
for _ in range(n):
    x = int(input())
    ans = 0
    for _ in range(x):
        a = input().split()
        ans += int(a[1])* float(a[2])
    print("$",f"{round(ans,2):.2f}",sep='')