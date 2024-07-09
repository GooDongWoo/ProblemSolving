import sys
def cantor(start,length):
    global original
    if(length==1):
        return
    else:
        cantor(start,length//3)
        original[start+length//3:start+length*2//3]=[' ']*(length//3)
        cantor(start+length*2//3,length//3)
        return 
try:
    while 1:    
        n=int(sys.stdin.readline())
        original=list('-'*(3**n))
        cantor(0,(3**n))
        sys.stdout.write(f'{"".join(original)}\n')
except:
    pass
        