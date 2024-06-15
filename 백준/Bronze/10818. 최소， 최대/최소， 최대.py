import sys
num=int(sys.stdin.readline())

tmp_list=[]
tmp_list.extend(map(int,sys.stdin.readline().split()))

print(f'{min(tmp_list)} {max(tmp_list)}')
