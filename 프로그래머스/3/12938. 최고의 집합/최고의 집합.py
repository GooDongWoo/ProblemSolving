def solution(n, s):
    if(n>s):
        return [-1]
    answer = [s//n]*(n)
    tmp=s-((s//n)*(n))
    if(tmp):
        for i in range(tmp):
            answer[n-1-i]+=1
    return answer