import sys
input = sys.stdin.readline

def find(num):
    if parents[num] != num:
        parents[num] = find(parents[num])
    return parents[num]

def union(x1, x2):
    my_p = find(x1)
    other_p = find(x2)
    if my_p == other_p: 
        return
    max_p, min_p = max(my_p, other_p), min(my_p, other_p)
    
    parents[max_p] = parents[min_p]
    return

g = int(input())
p = int(input())

parents = list(range(g))
v= [0] * g

gs = [int(input())-1 for _ in range(p)]
cnter = 0

for i in range(p):
    target = gs[i]
    tp = find(target)
    
    if v[tp] == 0:
        v[tp] = 1
        cnter += 1
    else:
        while tp > 0 and v[find(tp-1)] == 1:  
            union(target, tp-1)
            tp = find(tp-1)
        
        if tp == 0 and v[0] == 1:
            break
        v[find(tp-1)] = 1
        union(target, tp-1)
        cnter += 1

print(cnter)