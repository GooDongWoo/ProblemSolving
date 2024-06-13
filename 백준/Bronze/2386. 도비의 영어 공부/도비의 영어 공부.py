import sys
while 1:
    a=sys.stdin.readline().rstrip()
    if(a=='#'):
        break
    target,sentence=a[0],a[2:]
    sentence=sentence.lower()
    cnt=0
    for char1 in sentence:
        if(char1==target):
            cnt+=1
    sys.stdout.write(f'{target} {cnt}\n')