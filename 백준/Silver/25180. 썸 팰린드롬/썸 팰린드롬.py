import sys
n=int(sys.stdin.readline())
#함수;; 
#n이 들어왔을 때 1개 그 자체로(<10)인가? 아니면 2개가 가능인가? 수가 짝수이면 ㄱㄴ.. 이것도 안되면 3개로 나누어야 한다.
#2개로 나누면 각각이 무조건 왼쪽 오른쪽 대칭되어야 하는데 즉 2개로 나눈것도 1개 또는 짝수로만 나뉘어야 한다.-> 골때린다. -> 취소
def sol(n):
    cnter=0
    if(n>=18):
        cnter+=(n//18)*2
        n=n%18
    def divn(n):#무조건 18보다 작거나 같음
        nonlocal cnter
        if(n==0):
            cnter+=0
        elif 0<n<10:
            cnter+=1
        elif (n%2)==0:
            cnter+=2
        else:
            cnter+=3
    divn(n)
    sys.stdout.write(f'{cnter}')
sol(n)