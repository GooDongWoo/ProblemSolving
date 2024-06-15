def switch_case(value):
    return {
        1: 'C',
        2: 'B',
        3: 'A',
        4: 'E',
    }.get(value, 'D')

for _ in range(3):
    yoot = list(map(int, input().split()))
    yootName = ''
    yootNumber = sum(yoot)
    print(switch_case(yootNumber))