import sys
n=int(sys.stdin.readline())
b_list=list(map(int,sys.stdin.readline().split()))
inf=int(1e9)
#2차원 매트릭스 만들고 각각 포문을 그 지점에서 왼쪽 오른쪽으로 끝까지 가는데 
mat=[[0 for _ in range(n)] for _ in range(n)]
cnter=[0]*n
for i in range(n):
    cnt=0
    # 왼쪽으로는 기울기가 계속 작아져야 한다. 그렇다고 한 번 커졌다고 멈출 필요는 없고 그 지점은 fail이고 이후 계속 체크하면 된다.
    min1=inf
    for j in range(i-1,-1,-1):
        if((b_list[i]-b_list[j])/(i-j)<min1):
            cnt+=1
            min1=(b_list[i]-b_list[j])/(i-j)
    
    max1=-inf
    # 오른쪽으로는 기울기가 계속 커져야 한다.
    for j in range(i+1,n,1):
        if((b_list[i]-b_list[j])/(i-j)>max1):
            cnt+=1
            max1=(b_list[i]-b_list[j])/(i-j)
    cnter[i]=cnt
print(max(cnter))