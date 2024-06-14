import sys
test_case=3
for _ in range(test_case):
    flag=1
    a,b=map(list,sys.stdin.readline().split())
    normal_a_set=set(a)
    normal_b_set=set(b)
    if(normal_a_set==normal_b_set):
        sys.stdout.write(f'friends\n')
        continue
    else:
        length_a=len(a)
        length_b=len(b)
        if(length_b>1):
            if(b[0]=='1'):
                ch_b_set=set([chr(ord(b[0])+1),chr(ord(b[1])-1)]+b[2:])
                if(normal_a_set==ch_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
            else:
                ch_b_set=set([chr(ord(b[0])+1),chr(ord(b[1])-1)]+b[2:])
                if(normal_a_set==ch_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
                ch_b_set=set([chr(ord(b[0])-1),chr(ord(b[1])+1)]+b[2:])
                if(normal_a_set==ch_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
            for i in range(1,length_b-1):
                ch_b_set=set(b[:i]+[chr(ord(b[i])+1),chr(ord(b[i+1])-1)]+b[i+2:])
                if(normal_a_set==ch_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    break
                ch_b_set=set(b[:i]+[chr(ord(b[i])-1),chr(ord(b[i+1])+1)]+b[i+2:])
                if(normal_a_set==ch_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    break
            if not(flag):
                continue
        if(length_a>1):
            if(a[0]=='1'):
                ch_a_set=set([chr(ord(a[0])+1),chr(ord(a[1])-1)]+a[2:])
                if(ch_a_set==normal_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
            else:
                ch_a_set=set([chr(ord(a[0])+1),chr(ord(a[1])-1)]+a[2:])
                if(ch_a_set==normal_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
                ch_a_set=set([chr(ord(a[0])-1),chr(ord(a[1])+1)]+a[2:])
                if(ch_a_set==normal_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    continue
            for i in range(1,length_a-1):
                ch_a_set=set(a[:i]+[chr(ord(a[i])+1),chr(ord(a[i+1])-1)]+a[i+2:])
                if(ch_a_set==normal_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    break
                ch_a_set=set(a[:i]+[chr(ord(a[i])-1),chr(ord(a[i+1])+1)]+a[i+2:])
                if(ch_a_set==normal_b_set):
                    sys.stdout.write(f'almost friends\n')
                    flag=0
                    break
    if(flag):
        sys.stdout.write(f'nothing\n')