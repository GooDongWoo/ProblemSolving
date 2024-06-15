import sys
n=int(input())
if(n>0):
    tmp_list=[int(sys.stdin.readline()) for _ in range(n)]
    tmp_list.sort()
    end15=int(n*15/100 + 0.5)
    result=0
    for i in range(len(tmp_list)-2*end15):
        result+=tmp_list[end15+i]
    result=int(result/(len(tmp_list)-2*end15) + 0.5)
    print(result)
else:
    print(0)    