def chckFell(a):
    r_a=a[::-1]
    for i in range((len(a)//2) + 1):
        if(a[i]!=r_a[i]):
            return False
    return True

while(1):
    a=input()
    if(a=='0'):
        break
    a=list(a)
    if(chckFell(a)):
        print('yes')
    else:
        print('no')