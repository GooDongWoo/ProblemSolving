# 데이터 세트의 개수 입력 받기
n = int(input())

# 각 데이터 세트에 대해 처리
for _ in range(n):
    X, Y = map(int, input().split())
    
    # 좀비가 충분한 뇌를 먹었는지 확인
    if X >= Y:
        print("MMM BRAINS")
    else:
        print("NO BRAINS")