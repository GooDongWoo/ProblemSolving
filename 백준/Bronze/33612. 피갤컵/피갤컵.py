year = 2024
N = int(input())
month = (N-1)*7+8
month -= 1
diff = month // 12
month %= 12
month += 1
print(int(year+diff), int(month))