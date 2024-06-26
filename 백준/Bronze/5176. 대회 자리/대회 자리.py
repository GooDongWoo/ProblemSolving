test_case=int(input())
for _ in range(test_case):
    p,m=map(int,input().split())
    m_list=[0]*(m+1)
    cnt=0
    for _ in range(p):
        candidate=int(input())
        if(m_list[candidate]):
            cnt+=1
        else:
            m_list[candidate]=1
    print(cnt)
