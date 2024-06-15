n_test=int(input())
tmp_list=[0]*n_test
for i in range(n_test):
    tmp_list[i]=tuple(map(int,input().split()))

tmp_list.sort(key=lambda x: (x[0],x[1]))
for i in range(n_test):
    print(*tmp_list[i])