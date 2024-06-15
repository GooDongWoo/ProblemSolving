import sys
from collections import deque
test_case=int(sys.stdin.readline())
wave_list=[0]*101
init=[1,1,1,2,2]
for i in range(1,6):
    wave_list[i]=init[i-1]
que1=deque(init)
for i in range(6,101):
    wave_list[i]=wave_list[i-1]+que1.popleft()
    que1.append(wave_list[i])

for _ in range(test_case):
    tmp=int(sys.stdin.readline())
    sys.stdout.write(f'{wave_list[tmp]}\n')