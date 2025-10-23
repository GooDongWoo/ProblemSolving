s = input().strip()
white = s.count('B')
black = s.count('C')
pairs = white // 2 + black // 2
print(pairs)