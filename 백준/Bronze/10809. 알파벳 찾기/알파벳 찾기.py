a=list(input())

#ord('a')# a의 아스키코드
#chr(0) #0번째 아스키코드의 문자

first_idx=[-1]*26

#chr(i+ord('a'))# a+ i번째 아스키코드에 해당하는 문자
for idx,item in enumerate(a):
    if(first_idx[ord(item)-ord('a')]==-1):
        first_idx[ord(item)-ord('a')]=idx
for i in range(len(first_idx)):
    print(first_idx[i],end=' ')