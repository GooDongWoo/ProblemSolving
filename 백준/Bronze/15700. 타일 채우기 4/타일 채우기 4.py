# 입력 받기
N, M = map(int, input().split())

# 총 칸 수 계산
total_cells = N * M

# 최대 타일 개수 계산
if N % 2 == 1 and M % 2 == 1:  # 둘 다 홀수인 경우
    max_tiles = (total_cells - 1) // 2
else:  # 적어도 하나가 짝수인 경우
    max_tiles = total_cells // 2

print(max_tiles)