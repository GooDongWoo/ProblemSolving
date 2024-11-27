import sys
input=sys.stdin.readline

MAX = int(1e5)
primes = [1] * (MAX + 1)
primes[0] = primes[1] = 0

p_list = []
for i in range(MAX + 1):
    if primes[i]:
        p_list.append(i)
        for j in range(i * i, MAX + 1, i):
            primes[j] = 0

targets = [0] * (MAX + 2)
for i in range(len(p_list) - 1):
    for j in range(i + 1, len(p_list)):
        if (p_list[i] * p_list[j] > (MAX + 1)):break
        else: targets[p_list[i] * p_list[j]] = 1

t = int(input())
qs = [int(input()) for _ in range(t)]
for i in range(t):
    cs = qs[i]
    while targets[cs] == 0:cs += 1
    sys.stdout.write(f'{cs}\n')
