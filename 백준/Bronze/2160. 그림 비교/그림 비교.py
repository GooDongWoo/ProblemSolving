import sys
n=int(sys.stdin.readline())
a=[0]*n
for i in range(n):
    tmp_pic=[list(sys.stdin.readline().rstrip()) for _ in range(5)]
    for j in range(35):
        if(tmp_pic[j//7][j%7]=='.'):
            a[i]|=1<<j

def find1bit(a):
    cnt=0
    for _ in range(35):
        if(a&1):
            cnt+=1
        a>>=1
    return cnt

#모든 a들 중에서 2개씩 뽑아서 XOR 연산하고 0의 개수를 찾는다.(1의 개수에서 35개 빼면 되겠지.)
#최대값을 저장하고 최대값이 나오면 그때의 그림들 a,b를 저장한다.
max1=-1
res=[0,0]
for i in range(n-1):
    for j in range(i+1,n):
        tmp=35-find1bit(a[i]^a[j])
        if(tmp>max1):
            max1=tmp
            res[0],res[1]=i+1,j+1
print(*res)