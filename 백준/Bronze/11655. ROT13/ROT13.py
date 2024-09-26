bs=ord('A')
be=ord('Z')

ss=ord('a')
se=ord('z')

ns=ord('0')
ne=ord('9')

words=list(input().rstrip())
for i in range(len(words)):
    on=ord(words[i])
    if(bs<=on<=be):
        words[i]=chr(((on-bs+13)%26)+bs)
    elif(ss<=on<=se):
        words[i]=chr(((on-ss+13)%26)+ss)
    else:
        pass
print(''.join(words))