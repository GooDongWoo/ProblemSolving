import sys 
def computeFail(W):
    length = len(W)
    fail = [0] * length
    j = 0
    for i in range(1, length):
        while j > 0 and W[i] != W[j]:
            j = fail[j - 1]
        if W[i] == W[j]:
            j += 1
            fail[i] = j
    return fail

def KMP(a, b):
    length_a = len(a)
    length_b = len(b)
    fail = computeFail(b)
    
    result = []
    j = 0
    for i in range(length_a):
        while j > 0 and a[i] != b[j]:
            j = fail[j - 1]
        if a[i] == b[j]:
            if j == length_b - 1:
                result.append(i - length_b + 2)
                j = fail[j]
            else:
                j += 1
    return result
t = sys.stdin.readline().rstrip('\n')
p = sys.stdin.readline().rstrip('\n')
result = KMP(t, p)
print(len(result))
print(*result)