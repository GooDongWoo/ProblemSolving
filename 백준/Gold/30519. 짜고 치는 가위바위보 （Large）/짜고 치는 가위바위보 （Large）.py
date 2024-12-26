import sys
input = sys.stdin.readline


d1 = dict()
d1[('R', 'S')] = 0; d1[('S', 'P')] = 1; d1[('P', 'R')] = 2  #lighter do win
d1[('S', 'S')] = 3; d1[('P', 'P')] = 4; d1[('R', 'R')] = 5  #lighter do draw
d1[('P', 'S')] = 6; d1[('R', 'P')] = 7; d1[('S', 'R')] = 8  #lighter do lose

l = input().rstrip()
s = list(input().rstrip())
MAX = len(s)
MOD = int(1e9) + 7

cnter = [0] * 9
cnter[d1[l, s[0]]] += 1

for i in range(1, MAX):
    #tmp_S = cnter[0] + cnter[3] + cnter[6]    #current lighter do S
    #tmp_P = cnter[1] + cnter[4] + cnter[7]    #current lighter do P
    #tmp_R = cnter[2] + cnter[5] + cnter[8]    #current lighter do R
    tmp = cnter.copy()
    for idx, char in enumerate(['S', 'P', 'R']):
        # draw after ligter win -> wrong
        if char == s[i]:
            tmp[d1[char, s[i]]] += (cnter[idx + 3] + cnter[idx + 6]) % MOD
        else:
            tmp[d1[char, s[i]]] += (cnter[idx] + cnter[idx + 3] + cnter[idx + 6]) % MOD
    
    tmp[d1[l, s[i]]] += 1
    cnter = tmp

print(sum(cnter) % MOD)