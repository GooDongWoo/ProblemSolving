# 입력 받기
A = int(input())
B = int(input())
C = int(input())
D = int(input())
E = int(input())

total_time = 0

# 1. A가 0도 미만인 경우 (얼어있는 상태)
if A < 0:
    # -A℃부터 0℃까지 C초당 1℃씩 상승
    total_time += -A * C
    # 해동에 D초 소요
    total_time += D
    # 0℃부터 B℃까지 E초당 1℃씩 상승
    total_time += B * E
# 2. A가 0도 이상인 경우 (이미 얼어있지 않은 상태)
else:
    # A℃부터 B℃까지 E초당 1℃씩 상승
    total_time += (B - A) * E

print(total_time)