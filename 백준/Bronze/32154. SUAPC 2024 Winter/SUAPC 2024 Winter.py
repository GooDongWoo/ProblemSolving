d1=dict()
d1[1]=[1,1,1,1,1,1,1,1,0,1,0,1,1]
d1[2]=[1,0,1,0,1,1,1,1,1,0,0,1,1]
d1[3]=[1,0,1,0,1,1,1,1,1,0,0,1,1]
d1[4]=[1,1,1,0,1,1,1,1,0,0,0,1,1]
d1[5]=[1,0,1,0,1,1,1,1,0,0,0,1,1]
d1[6]=[1,0,1,0,1,1,1,1,0,0,0,1,1]
d1[7]=[1,0,1,0,1,1,1,1,0,0,0,1,1]
d1[8]=[1,0,1,0,1,1,1,1,0,0,0,1,1]
d1[9]=[1,0,1,0,1,1,1,1,0,0,0,1,1]
d1[10]=[1,1,1,0,0,1,1,1,0,0,0,1,1]

n=int(input())
print(sum(d1[n]))
for i in range(len(d1[n])):
    if(d1[n][i]):
        print(chr(ord('A')+i),end=' ')
        