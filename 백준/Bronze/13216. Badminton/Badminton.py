import sys

def solve():
    # 입력 문자열 읽기 (공백 제거)
    data = sys.stdin.read().strip()
    
    scoreA = 0
    scoreB = 0
    winsA = 0
    winsB = 0
    
    for char in data:
        if char == 'A':
            scoreA += 1
        elif char == 'B':
            scoreB += 1
        
        if scoreA == 21 or scoreB == 21:
            print(f"{scoreA}-{scoreB}")
            
            if scoreA == 21:
                winsA += 1
            else:
                winsB += 1
            
            scoreA = 0
            scoreB = 0
            
            if winsA == 2:
                print("A")
                break
            if winsB == 2:
                print("B")
                break

if __name__ == "__main__":
    solve()