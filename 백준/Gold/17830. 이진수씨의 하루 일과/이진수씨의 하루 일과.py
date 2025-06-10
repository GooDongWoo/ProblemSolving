def get_result_bits(N, B_str):
    # leading zero 제거
    B_str = B_str.lstrip('0')
    
    # B가 0인 경우
    if not B_str or B_str == '0':
        return 1
    
    B_bits = len(B_str)  # B의 자릿수 (leading zero 제거 후)
    
    # B의 최고자리수 미만의 자리에 1이 있는지 확인
    has_one_below_highest = '1' in B_str[1:]
    
    if has_one_below_highest:
        return N + B_bits
    else:
        return N + B_bits - 1

def solve(N, B_pattern):
    B_max_str = B_pattern.replace('?', '1')
    B_min_str = B_pattern.replace('?', '0')
    
    max_bits = get_result_bits(N, B_max_str)
    min_bits = get_result_bits(N, B_min_str)
    
    return max_bits, min_bits

T = int(input())
for _ in range(T):
    N, B_pattern = input().split()
    N = int(N)
    max_bits, min_bits = solve(N, B_pattern)
    print(max_bits, min_bits)