n = int(input())
for i in range(n):
    menu = input().split()
    set1 = menu[1:]
print(len(set1))
print('\n'.join(set1))