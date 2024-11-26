import sys
input=sys.stdin.readline

class tree:
    def __init__(self, idx):
        self.p = idx
        self.c = []

def findP(node_num):
    global stats
    return stats[node_num].p

def union_(num1, num2): # make n2 -> n1's child
    global stats
    n1_p = findP(num1)
    n2_p = findP(num2)
    
    if len(stats[n1_p].c) < len(stats[n2_p].c):n2_p, n1_p = n1_p, n2_p
    
    stats[n1_p].c.extend(stats[n2_p].c)
    stats[n1_p].c.append(n2_p)
    for child in stats[n2_p].c:
        stats[child].p = n1_p
    
    stats[n2_p].p = n1_p
    stats[n2_p].c = []
    return 

n, m = map(int, input().split())

stats =[tree(i) for i in range(n)]
qs = [tuple(map(int, input().split())) for _ in range(m)]

for i in range(m):
    n1, n2 = qs[i]
    if (findP(n1) == findP(n2)):
        print(i + 1)
        exit()

    else:union_(n1, n2)

print(0)