n,l=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
nmat=[*zip(*mat)]

def rowchck(t,mat=mat):
    global n,l
    target=mat[t]
    blocks=[[target[0]]]
    slopes=[[0]]
    for i in range(1,n):
        if(target[i]==blocks[-1][0]):blocks[-1].append(target[i]);slopes[-1].append(0)
        else:blocks.append([target[i]]);slopes.append([0])
    
    if(len(blocks)==1):return True
    for i in range(len(blocks)-1):
        if(abs(blocks[i][-1]-blocks[i+1][0])==1):
            if (blocks[i][-1]>blocks[i+1][0] and len(blocks[i+1])>=l):
                slopes[i+1][:l]=[1]*l
            elif(blocks[i][-1]<blocks[i+1][0] and len(blocks[i])>=l and any(slopes[i][-l:])==0):
                slopes[i][-l:]=[1]*l
            else:return False
        else: return False
    return True

def colchck(t,mat=mat):
    global nmat
    return rowchck(t,nmat)

cnter=0
for i in range(n):
    cnter+=int(rowchck(i))
for i in range(n):
    cnter+=int(colchck(i))
print(cnter)