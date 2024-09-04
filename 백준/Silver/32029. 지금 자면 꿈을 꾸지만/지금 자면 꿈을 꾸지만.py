import sys
N,A,B=map(int,sys.stdin.readline().split())
tls=sorted([*map(int,sys.stdin.readline().split())])
result=[]
#잠 안잘때
cnter=0
time=0
tls_idx=0
while tls_idx<N:
    if tls[tls_idx]>=(time+A):
        cnter+=1
        time+=A
    tls_idx+=1
result.append(cnter)

for i in range(N):#잠 잘때, 0-> 시작부터 잠,
    for j in range(1, A): #각각 b*j시간 잘 수 있다.
        if(i==0):
            cnter=0
            time=B*j
            a=A-j
            tls_idx=0
            while tls_idx<N:
                if tls[tls_idx]>=(time+a):
                    cnter+=1
                    time+=a
                tls_idx+=1
            result.append(cnter)
        else:
            cnter=0
            time=0
            a=A
            tls_idx=0
            while tls_idx<i:
                if tls[tls_idx]>=(time+a):
                    cnter+=1
                    time+=a
                tls_idx+=1
            time+=B*j
            a=a-j
            while tls_idx<N:
                if tls[tls_idx]>=(time+a):
                    cnter+=1
                    time+=a
                tls_idx+=1
            result.append(cnter)

print(max(result))