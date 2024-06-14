import sys

n1=[(set(sorted([(0,0),(0,1),(0,2),(0,3)])))]#1
n1.append(set(sorted([(0,0),(1,0),(2,0),(3,0)])))#6

n1.append(set(sorted([(0,0),(0,1),(1,0),(1,1)])))#2

n1.append(set(sorted([(0,0),(0,1),(0,2),(1,2)])))#3
n1.append(set(sorted([(0,0),(0,1),(0,2),(-1,2)])))#7
n1.append(set(sorted([(0,0),(-1,0),(-2,0),(-2,1)])))#3
n1.append(set(sorted([(0,0),(-1,0),(-2,0),(-2,-1)])))#7
n1.append(set(sorted([(0,0),(0,-1),(0,-2),(1,-2)])))#3
n1.append(set(sorted([(0,0),(0,-1),(0,-2),(-1,-2)])))#7
n1.append(set(sorted([(0,0),(1,0),(2,0),(2,1)])))#3
n1.append(set(sorted([(0,0),(1,0),(2,0),(2,-1)])))#7

n1.append(set(sorted([(0,0),(1,0),(1,1),(2,1)])))#4
n1.append(set(sorted([(0,0),(1,0),(1,-1),(2,-1)])))#4
n1.append(set(sorted([(0,0),(0,1),(-1,1),(-1,2)])))#4
n1.append(set(sorted([(0,0),(0,1),(1,1),(1,2)])))#4
n1.append(set(sorted([(0,0),(-1,0),(-1,-1),(-2,-1)])))#4
n1.append(set(sorted([(0,0),(-1,0),(-1,1),(-2,1)])))#4
n1.append(set(sorted([(0,0),(0,-1),(1,-1),(1,-2)])))#4
n1.append(set(sorted([(0,0),(0,-1),(-1,-1),(-1,-2)])))#4


n1.append(set(sorted([(0,0),(0,1),(0,2),(1,1)])))#5
n1.append(set(sorted([(0,0),(0,1),(0,2),(-1,1)])))#5
n1.append(set(sorted([(0,0),(1,0),(2,0),(1,1)])))#5
n1.append(set(sorted([(0,0),(1,0),(2,0),(1,-1)])))#5


def chckIn(i,j,picture1):
    global n1,stat_mat,n,m
    for dy,dx in picture1:
        if not (0<=dy+i<=(n-1) and  0<=dx+j<=(m-1)):
            return False
    return True
def sumFunc(i,j,picture1):
    global n1,stat_mat,n,m
    result=0
    for dy,dx in picture1:
        result+=stat_mat[dy+i][dx+j]
    return result

n,m=map(int,sys.stdin.readline().split())
stat_mat=[]
for _ in range(n):
    stat_mat.append(list(map(int,sys.stdin.readline().split())))

max1=0
for i in range(n):
    for j in range(m):
        for picture1 in n1:
            if(chckIn(i,j,picture1)):#넘는 칸 있는지 체크
                #넘지 않으면 다 더해보고 
                result=sumFunc(i,j,picture1)# 다 더한 값
                if(result>max1):#max값과 비교 후 갱신
                    max1=result
print(max1)
        
        
'''
def rotatep90(set1):
    tmp=[]
    for item in set1:
        tmp.append((item[1],item[0]))
    return set(sorted(tmp))

def mirrorlr(set1):
    tmp=[]
    for item in set1:
        tmp.append((item[0],-item[1]+3))
    return set(sorted(tmp))
'''