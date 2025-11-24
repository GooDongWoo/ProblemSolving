import sys

input = sys.stdin.readline

def main():
    try:
        line = input().strip()
        if not line: return
        T = int(line)
    except ValueError:
        return

    for _ in range(T):
        try:
            line = input().split()
            if not line: break
            N, D = map(int, line)
        except ValueError:
            break
        
        ans = 0
        
        for _ in range(N):
            v, f, c = map(int, input().split())
            if f * v >= D * c:
                ans += 1
                
        print(ans)

if __name__ == "__main__":
    main()