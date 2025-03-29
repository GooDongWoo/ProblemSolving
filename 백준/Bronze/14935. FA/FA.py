def F(x):
    # 문자열로 변환하여 첫 자리와 자리수 구하기
    x_str = str(x)
    first_digit = int(x_str[0])
    num_digits = len(x_str)
    return first_digit * num_digits

def is_FA(x):
    seen = set()  # 이미 계산한 값을 저장
    
    while x not in seen:
        seen.add(x)
        x = F(x)
    
    return True

# 입력 받기
x = int(input())

# FA수인지 확인
if is_FA(x):
    print("FA")
else:
    print("NFA")