import sys
input = sys.stdin.readline

# 입력을 받아 x와 k 값을 정수로 저장
x_value, k_value = map(int, input().split())

# k_value를 2진수 문자열로 변환 후, 리스트로 저장
k_bits = list(map(int, bin(k_value)[2:]))

# x_value를 2진수 문자열로 변환 후, 리스트로 저장
x_bits = list(map(int, bin(x_value)[2:]))

# 변환 결과를 저장할 빈 문자열 생성
result_bits = ""

# k_bits 리스트가 비어 있지 않은 동안 반복
while k_bits:
    # x_bits가 비어있지 않으면
    if x_bits:
        # x의 마지막 비트를 pop으로 꺼내서 처리
        current_x_bit = x_bits.pop()

        # 만약 x의 현재 비트가 1이면, 결과에 0을 추가 (1이면 k의 비트를 사용하지 않음)
        if current_x_bit == 1:
            result_bits += str(0)
        # x의 비트가 0일 경우, k의 마지막 비트를 pop하여 결과에 추가
        else:
            result_bits += str(k_bits.pop())
    # x_bits가 비어 있으면 남은 k_bits 비트를 모두 결과에 추가
    else:
        result_bits += str(k_bits.pop())

# 결과 result_bits를 역순으로 바꿔서 이진수 문자열로 만든 후, 다시 10진수로 변환하여 출력
print(int("0b" + result_bits[::-1], 2))
