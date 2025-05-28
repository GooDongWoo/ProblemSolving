a = int(input())
b = list(map(int,input().split()))
print(sum([1 for i in b if i==a]))