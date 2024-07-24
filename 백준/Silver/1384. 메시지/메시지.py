import sys
idx=1
while 1:    
    n=int(sys.stdin.readline())
    if(n==0):
        break
    name=[]
    mem=[]
    for i in range(n):
        tmp=sys.stdin.readline().split()
        name.append(tmp[0])
        mem.append(tmp[1:])
    
    g=[]
    for i in range(n):
        for j in range(n-1):
            if('N' == mem[i][j]):
                g.append(((n+i-1-j)%n,i))
        
    print('Group',idx)
    if(len(g)):
        for i in range(len(g)):
            print(name[g[i][0]],'was nasty about',name[g[i][1]])
    else:
        print('Nobody was nasty')
    print()
    idx+=1