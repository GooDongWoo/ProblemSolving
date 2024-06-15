n_test=int(input())
test_list=list(map(int,input().split()))
cnt=0
def checkPri(a):
    if(a<2):
        return False
    for i in range(2,(a//2)+1):
        if((a%i)==0):
            return False
    return True
for i in test_list:
    if(checkPri(i)):
        cnt+=1
print(cnt)