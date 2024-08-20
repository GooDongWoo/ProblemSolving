def decrypt(n, pw):
    if len(pw)&1:pw=pw[:-1]
    aft=[]
    idx=0
    while idx<len(pw):
        aft.append(chr((ord(pw[idx])-ord('a')+ord(pw[idx+1])-ord('a')-n)%26+ord('a')))
        idx+=2
    return aft
    
n=int(input())
pw=input().rstrip().split()
aft=[]
for word in pw:
    aft.extend(decrypt(n, word))
    aft.append(' ')
aft.pop()
print(''.join(aft))