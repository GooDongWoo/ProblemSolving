import sys
n=int(sys.stdin.readline()) #항상 짝수
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]

# 먼저 첫번째 놈을 반드시 포함하고 그런 상태에서 한 팀에 n/2명을 채워야함-> bt로 일일이 다 구하고 
# 브루트 포스로 각 배열 돌면서 그 팀의 수치 구하고 다른 팀도 동시에 각각 더해서 구한다. 그리고 차이를 res에 넣어서 저장한다.
team1=[0]*(n//2)
result=[]
def bt(idx):#0번은 포함되었다고 생각하고 1~n-1 중에서 n/2 -1명을 뽑는다.
    global n,mat,team1,result
    if(idx== (n//2)):
        team2=[]
        for i in range(n):
            if(i not in team1):
                team2.append(i)
        res1=0
        for i in team1:
            for j in team1:
                res1+=mat[i][j]
        res2=0
        for i in team2:
            for j in team2:
                res2+=mat[i][j]
        result.append(abs(res1-res2))
    else:
        for i in range(team1[idx-1]+1,n):
            team1[idx]=i
            bt(idx+1)
bt(1) #idx 1부터 시작

print(min(result))