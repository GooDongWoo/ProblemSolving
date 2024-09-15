cnter=0
while 1:
    cnter+=1
    l1=list(map(int,input().split()))
    if(0 in l1):break
    target=l1.index(-1)
    print(f'Triangle #{cnter}')
    target_alphabet=chr(target+ord('a'))
    if(target==2):
        res=(l1[1]**2+ l1[0]**2)
    elif(target==1):
        res=(l1[2]**2- l1[0]**2)
    else:
        res=(l1[2]**2- l1[1]**2)
    if(res<=0):
        print('Impossible.')
    else:
        print(f'{target_alphabet} = {res**(0.5):.3f}')
    print()