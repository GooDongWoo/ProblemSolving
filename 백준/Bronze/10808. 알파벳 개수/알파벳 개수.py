a=input().rstrip()
cnter=[0]*26
for i in a:
    cnter[ord(i)-ord('a')]+=1
print(*cnter)