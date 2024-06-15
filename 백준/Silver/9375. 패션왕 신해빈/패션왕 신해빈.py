import sys

test_case=int(sys.stdin.readline())

for _ in range(test_case):
    num_clothes=int(sys.stdin.readline())
    dict1=dict()
    tot=1
    for _ in range(num_clothes):
        name_c,type_c=(sys.stdin.readline().split())
        if(type_c in dict1):
            dict1[type_c]+=1
        else:
            dict1[type_c]=1
    
    for each_num in dict1.values():
        tot*=each_num+1
    sys.stdout.write(f'{tot-1}\n')