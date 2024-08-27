dices=list(map(int, input().split()))
route=[[i for i in range(0,41,2)]]
route.append([10,13,16,19])
route.append([20,22,24])
route.append([30,28,27,26])
route.append([25,30,35,40])
cases=[]
target=[0, 0, 1, 0, 2, 2, 2, 0, 2, 2]
def makecases():
    global cases
    tmp=[0]*10
    def cb(idx=0):
        nonlocal tmp
        if idx==10:
            cases.append(tmp[:])
            return
        else:
            for i in range(4):
                tmp[idx]=i
                cb(idx+1)
    cb()
makecases()
#10,20,30-> blue
#해당 위치에 이미 다른 말이 있으면 안됨 그런 경우는 바로 다음 케이스로 넘어간다.
max_score=0
for case in cases:
    units=[[0,0] for _ in range(4)]# [cr, cidx], idx:-1 equal to end
    v=[[0]*len(route[0]) for _ in range(5)]
    score=0
    ctn_F=False
    for unit,dice in zip(case,dices):
        if units[unit][1]==-1:  #도착점에 있는 말을 움직이려할때
            ctn_F=True
            break
        cr,cidx=units[unit]
        v[cr][cidx]=0   #시작할때 v에서 지운다.
        if cidx+dice<len(route[cr]):# 아직 각 경로에서 내부에 존재한다.
            score+=route[cr][cidx+dice]
            if cr==0 and (route[0][cidx+dice] in [10,20,30,40]):#[10,20,30]인 점에 접근할때
                cr=(route[0][cidx+dice]//10)
                cidx=0 if cr!=4 else 3
            else:
                cidx+=dice
            if(v[cr][cidx]):ctn_F=True;break#이미 있는 점에 접근하려 할때             
            v[cr][cidx]=1
        elif cr not in [0,4] and (3+len(route[cr]))>=cidx+dice>=len(route[cr]):
            cidx=cidx+dice-len(route[cr])
            cr=4
            score+=route[cr][cidx]
            if(v[cr][cidx]):ctn_F=True;break#이미 있는 점에 접근하려 할때 
            v[cr][cidx]=1
        else:
            cidx=-1
        units[unit]=cr,cidx
    if not (ctn_F):
        max_score=max(max_score,score)
print(max_score)