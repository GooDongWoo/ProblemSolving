import sys
import collections
N=int(input())
N_list=list(map(int,sys.stdin.readline().split()))

M=int(input())
M_list=list(map(int,sys.stdin.readline().split()))

cnt1=collections.Counter(N_list)
for item in M_list:
    sys.stdout.write(f'{cnt1[item]} ')