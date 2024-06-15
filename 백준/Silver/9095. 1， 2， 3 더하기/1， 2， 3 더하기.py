import sys
n=[0]*11
def fact(a):
    result=1
    for i in range(2,a+1):
        result*=i
    return result
for i in range(1,11): # 전체 n배열 구하기
    cnt=0
    for j in range((i//3)+1):# 3의 개수
        for k in range((((i-(3*j))//2)+1)): # 2의 개수
            tmp_sum=j+k+(i-(3*j)-(2*k))
            cnt=fact(tmp_sum)/((fact(j))*(fact(tmp_sum-j)))*fact(tmp_sum-j)/((fact(k))*(fact(tmp_sum-j-k)))
            n[i]+=int(cnt)
         
t=int(input())
for _ in range(t):
    tmp=int(sys.stdin.readline())
    sys.stdout.write(f'{n[tmp]}\n')