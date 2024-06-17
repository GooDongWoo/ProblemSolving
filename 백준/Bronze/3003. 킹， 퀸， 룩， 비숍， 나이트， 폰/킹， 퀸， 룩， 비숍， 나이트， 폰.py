'''
 킹 1개, 퀸 1개, 룩 2개, 비숍 2개, 나이트 2개, 폰 8개로 구성되어 
'''
a=list(map(int,input().split()))
ans=[1,1,2,2,2,8]
for i in range(len(ans)):
    print(ans[i]-a[i],end=' ')