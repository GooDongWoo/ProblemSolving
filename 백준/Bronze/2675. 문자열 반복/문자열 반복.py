n_test=int(input())
for _ in range(n_test):
    opnd, str1=input().split()
    opnd=int(opnd)
    str1=list(str1)
    for eachChar in str1:
        print(eachChar*opnd,end='')
    print()
