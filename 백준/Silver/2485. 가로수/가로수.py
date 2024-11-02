import sys
from math import lcm,gcd

input=sys.stdin.readline

n=int(input())
l=[int(input()) for _ in range(n)]
diff_set=set()
for i in range(1,n):
    diff_set.add(l[i]-l[i-1])

diff_list=gcd(*list(diff_set))
print((l[-1]-l[0])//diff_list + 1 - (n))