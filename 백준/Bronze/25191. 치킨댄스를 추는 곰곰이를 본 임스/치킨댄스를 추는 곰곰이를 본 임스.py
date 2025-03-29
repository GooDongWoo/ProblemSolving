# 입력 받기
N = int(input())  # 치킨집에 있는 치킨의 총 개수
A, B = map(int, input().split())  # 임스의 집에 있는 콜라(A)와 맥주(B)의 개수

# 콜라로 시킬 수 있는 치킨 개수
cola_chicken = A // 2  # 콜라 2개당 치킨 1마리

# 콜라와 맥주로 시킬 수 있는 최대 치킨 개수
max_possible_chicken = cola_chicken + B

# 치킨집 재고와 비교하여 최종 결과 계산
result = min(N, max_possible_chicken)

# 결과 출력
print(result)