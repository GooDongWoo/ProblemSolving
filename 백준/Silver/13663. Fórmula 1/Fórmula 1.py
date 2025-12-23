import sys

def solve():
    input_data = sys.stdin.read().split()
    idx = 0
    
    while idx < len(input_data):
        G = int(input_data[idx])
        P = int(input_data[idx+1])
        idx += 2
        
        if G == 0 and P == 0:
            break
            
        races = []
        for _ in range(G):
            races.append(list(map(int, input_data[idx:idx+P])))
            idx += P
            
        S = int(input_data[idx])
        idx += 1
        
        for _ in range(S):
            K = int(input_data[idx])
            points_system = list(map(int, input_data[idx+1:idx+1+K]))
            idx += 1 + K
            
            total_scores = [0] * (P + 1)
            for r in range(G):
                for d in range(P):
                    rank = races[r][d]
                    if rank <= K:
                        total_scores[d+1] += points_system[rank-1]
            
            max_score = max(total_scores)
            winners = []
            for d in range(1, P + 1):
                if total_scores[d] == max_score:
                    winners.append(str(d))
            
            print(" ".join(winners))

if __name__ == "__main__":
    solve()