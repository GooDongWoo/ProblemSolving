import sys 
def computeFail(W): 
    length = len(W) 
    fail = [0] * length 
    j = 0  # 일치한 문자 개수 초기화
    for i in range(1, length):  
        while j > 0 and W[i] != W[j]:  # 일치하지 않는 경우
            j = fail[j - 1]  # 이전 일치한 위치로 이동 
            #-> Why? (지금 구한 j(당연히 그 구간에서 최대로 겹치는 부분:x)보단 작지만 x내부에서 반복되는 소구간의 중간 부분일 수 있으니까) ex)aabaa'a' 파트
        if W[i] == W[j]:  # 문자가 일치하는 경우
            j += 1  # 일치한 문자 개수 증가
            fail[i] = j  # 실패 함수 갱신
    return fail

def KMP(a, b):  
    length_a = len(a)
    length_b = len(b)
    fail = computeFail(b)
    result = []
    j = 0  # 패턴 문자열(b)의 현재 위치 초기화
    for i in range(length_a):  
        while j > 0 and a[i] != b[j]:  # 일치하지 않는 경우
            j = fail[j - 1]  # 실패 함수에 따라 위치 이동
        if a[i] == b[j]:  
            if j == length_b - 1:  # 패턴 문자열의 끝까지 일치한 경우
                result.append(i - length_b + 2)  
                j = fail[j]  # 다음 비교를 위해 실패 함수 값으로 이동
            else:  # 아직 패턴 문자열의 끝이 아닌 경우
                j += 1  # 패턴 문자열의 다음 문자로 이동
    return result 

t = sys.stdin.readline().rstrip('\n')  
p = sys.stdin.readline().rstrip('\n')  
result = KMP(t, p)  
print(len(result))  
print(*result) 