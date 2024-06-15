n_test=int(input())
a=set()
for _ in range(n_test):
    a.add(input())
a=sorted(list(a))
len_list=[[] for _ in range(51)]
for item in a:
    len_list[len(item)].append(item)

for in_list in len_list:
    for item in in_list:
        print(item)