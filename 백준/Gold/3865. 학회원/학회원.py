import sys
from collections import deque
input=sys.stdin.readline

while 1:
    n = int(input())
    if n == 0: break
    
    k_set = set()
    k2i = dict()
    i2k = dict()
    kd_list = [set() for _ in range(n)]
    
    for i in range(n):
        key, datas = input().rstrip().rstrip('.').split(':')
        datas = list(datas.split(','))
        k_set.add(key)
        k2i[key] = i
        i2k[i] = key
        kd_list[i] = set(datas)

    adj_v =[[] for _ in range(n)]
    in_cnter = [0] * n
    for idx, vals in enumerate(kd_list):
        intersections = (k_set & vals)
        in_cnter[idx] += len(intersections)
        for par in list(intersections):
            adj_v[k2i[par]].append(idx)

    q = deque()    
    for i in range(n):
        if in_cnter[i] == 0:
            q.append(i)
    while q:
        cur_idx = q.popleft()
        
        intersections = (k_set & kd_list[cur_idx])
        if intersections:
            for par in list(intersections):
                kd_list[cur_idx].discard(par)
                for item in kd_list[k2i[par]]:
                    kd_list[cur_idx].add(item)
        
        for i in adj_v[cur_idx]:
            in_cnter[i] -= 1
            if in_cnter[i] == 0:
                q.append(i)

    print(len(kd_list[0]))