def solve():
    a, b = map(int, input().split())
    
    start = max(4, a)
    if start % 2 == 1:  # start가 홀수면 다음 짝수로
        start += 1
    
    if start > b:
        print(0)
    else:
        last_even = b if b % 2 == 0 else b - 1
        
        if start > last_even:
            print(0)
        else:
            # 등차수열의 합: 개수 × (첫째항 + 마지막항) / 2
            count = (last_even - start) // 2 + 1
            result = count * (start + last_even) // 2
            print(result)

solve()