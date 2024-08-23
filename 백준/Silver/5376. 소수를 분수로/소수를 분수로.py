import sys
n=int(sys.stdin.readline())
def gcd(a1,a2):
    b=max(a1,a2)
    s=min(a1,a2)
    if(b%s==0):return s
    return gcd(s,b%s)

for _ in range(n):
    raw=sys.stdin.readline().rstrip()
    raw=raw[2:]
    if('(' in raw):
        start=raw.index('(')
        end=len(raw)-1
        iternum=end-start-1
        
        iter_p=raw[start+1:end]
        front_p=raw[:start] if raw[:start]!='' else '0'
        total_p=front_p+iter_p
        
        top=(int(total_p)-int(front_p))
        bot=(10**iternum-1)*(10**(start))
        
        gcdnum=gcd(top,bot)
        print(top//gcdnum,'/',bot//gcdnum,sep='')
    else:
        length=len(raw)
        if(length==0):print(0)
        else:
            bot=10**length
            top=int(raw)
            gcdnum=gcd(top,bot)
            print(top//gcdnum,'/',bot//gcdnum,sep='')