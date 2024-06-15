import sys
import math
lag_v=[100]*50001
lag_v[0]=0
lag_v[1]=1
for i in range(2,50001):
    max_sqrt=int(math.sqrt(i))
    for j in range(max_sqrt,0,-1):
        lag_v[i]=min(lag_v[i-(j**2)]+1,lag_v[i])
n=int(sys.stdin.readline())
sys.stdout.write(f'{lag_v[n]}')