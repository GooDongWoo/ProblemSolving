import sys
n,m=map(int,sys.stdin.readline().split())
dict1=dict()
for i in range(n+1):
    dict1[i]=[i]
for _ in range(m):
    optr,a,b=map(int,sys.stdin.readline().split())
    if(optr==0):#union
        if(a==b):
            continue
        
        if(type(dict1[b])==int):#대표가 아니라 일원임
            repre_b=dict1[b]
            tmp_b=dict1[repre_b]  
        else:#본인이 대표임
            repre_b=b
            tmp_b=dict1[repre_b]
        if(type(dict1[a])==int):
            repre_a=dict1[a]
            tmp_a=dict1[repre_a]
        else:
            repre_a=a
            tmp_a=dict1[repre_a]
        
        if(repre_b!=repre_a):
            if(len(tmp_a)>len(tmp_b)):#b를 a에 달아야지
                tmp_a.extend(tmp_b)
                for v in tmp_b:
                    dict1[v]=repre_a
            else:
                tmp_b.extend(tmp_a)
                for v in tmp_a:
                    dict1[v]=repre_b

    else:#find
        if(type(dict1[b])==int):#대표가 아니라 일원임
            repre_b=dict1[b]
        else:#본인이 대표임
            repre_b=b            
        if(type(dict1[a])==int):
            repre_a=dict1[a]
        else:
            repre_a=a
        if(repre_a==repre_b):
            sys.stdout.write(f'YES\n')
        else:
            sys.stdout.write(f'NO\n')