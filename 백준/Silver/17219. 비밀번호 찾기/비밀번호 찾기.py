import sys
N,M=map(int,input().split())
dict1=dict()
for _ in range(N):
    dict1.update([tuple(sys.stdin.readline().split())])

for _ in range(M):
    tmp=sys.stdin.readline().strip()
    sys.stdout.write(f'{dict1[tmp]}\n')