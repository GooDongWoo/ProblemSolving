n=int(input())
arr=[0]*26
for _ in range(n):
    name=input().rstrip()
    arr[ord(name[0])-ord('a')]+=1

cnt=0
for i in range(26):
    if(arr[i]>=5):
        cnt+=1
        print(chr(i+ord('a')),end='')
if(not cnt):
    print('PREDAJA')