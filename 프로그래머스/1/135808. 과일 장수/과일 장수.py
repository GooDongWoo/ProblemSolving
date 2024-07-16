def solution(k, m, score):
    answer = 0
    nscore= sorted(score,reverse=True)
    idx=m-1
    while idx<len(nscore):
        answer+=nscore[idx]*m
        idx+=m
    return answer