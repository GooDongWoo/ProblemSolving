import sys
input = sys.stdin.readline

N = int(input())
start = int((N * 2) ** (0.5))
diff = N - (start * (start + 1))//2
if not(0<= diff < start+1):
    start -= 1
    diff = N - (start * (start + 1))//2

if start&1:
    if diff == 0:
        c, p = 1, start
    else:
        c, p = 0 + diff, start + 2 - diff
else:
    if diff == 0:
        c, p = start, 1
    else:
        c, p = start + 2 - diff, 0 + diff

print(f'{c}/{p}\n')