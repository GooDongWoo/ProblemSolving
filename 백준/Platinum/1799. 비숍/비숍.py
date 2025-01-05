import sys
input = sys.stdin.readline

def get_positions(n, mat):
   white = []  # 흰 칸 위치
   black = []  # 검은 칸 위치
   for i in range(n):
       for j in range(n):
           if mat[i][j] == 0:
               continue
           if (i + j) % 2 == 0:
               white.append((i, j))
           else:
               black.append((i, j))
   return white, black

def solve(positions):
   n = len(positions)
   if n == 0:
       return 0
       
   def backtrack(idx, diag1, diag2, count):
       if idx == n:
           return count
           
       result = backtrack(idx + 1, diag1, diag2, count)  # 비숍을 놓지 않는 경우
       
       y, x = positions[idx]
       # 비숍을 놓을 수 있는 경우
       if not (diag1 & (1 << (y + x)) or diag2 & (1 << (y - x + N - 1))):
           new_diag1 = diag1 | (1 << (y + x))
           new_diag2 = diag2 | (1 << (y - x + N - 1))
           result = max(result, backtrack(idx + 1, new_diag1, new_diag2, count + 1))
       
       return result

   return backtrack(0, 0, 0, 0)

N = int(input())
mat = [list(map(int, input().split())) for _ in range(N)]

# 흰 칸과 검은 칸 분리
white_pos, black_pos = get_positions(N, mat)

# 각각의 칸에 대해 최대 비숍 수 계산 
white_result = solve(white_pos)
black_result = solve(black_pos)

print(white_result + black_result)