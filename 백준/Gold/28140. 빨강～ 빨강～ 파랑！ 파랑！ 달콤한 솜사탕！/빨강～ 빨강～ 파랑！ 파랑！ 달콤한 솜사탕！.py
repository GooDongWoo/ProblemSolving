import sys
input=sys.stdin.readline

def bs_l(l, target) : # bs_left
    start = 0; end = len(l) - 1
    while start <= end :
        mid = (start + end) // 2
        if l[mid] < target:
            start = mid + 1
        else:
            end = mid - 1
    return start

n, q = map(int, input().split())
word = input().rstrip()
rl = []
bl = []
for i in range(n):
    if word[i] == 'R':
        rl.append(i)
    elif word[i] == 'B':
        bl.append(i)

for _ in range(q):
    s, e = map(int, input().split())
    r_start_idx_in_rl = bs_l(rl, s)
    if r_start_idx_in_rl + 1 >= len(rl):
        sys.stdout.write(f'-1\n'); continue
        
    b_start_idx = rl[r_start_idx_in_rl + 1]
    b_start_idx_in_bl = bs_l(bl, b_start_idx)
    
    if b_start_idx_in_bl + 1 >= len(bl) or (b_start_idx_in_bl + 1 < len(bl) and bl[b_start_idx_in_bl + 1] > e):
        sys.stdout.write(f'-1\n'); continue
        
    sys.stdout.write(f'{rl[r_start_idx_in_rl]} {rl[r_start_idx_in_rl + 1]} {bl[b_start_idx_in_bl]} {bl[b_start_idx_in_bl + 1]}\n')