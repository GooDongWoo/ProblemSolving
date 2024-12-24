s, k, h = map(int, input().split())
d = dict()
d[s] = 'Soongsil'
d[k] = 'Korea'
d[h] = 'Hanyang'
if s + k + h >= 100:
    print('OK')
else:
    tmp = min(s, k, h)
    print(d[tmp])