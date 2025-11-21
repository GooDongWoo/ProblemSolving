n = int(input())
arr = list(map(int, input().split()))
arr2 = list(map(int, input().split()))
cnt = 0;
for i in range(n):
    if(arr2[i]-arr[i] >= 0):
        cnt+=1;
print(cnt)