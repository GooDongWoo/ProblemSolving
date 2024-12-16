import sys
input = sys.stdin.readline

dap = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
dates = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
x, y = map(int, input().split())
print(dates[(sum(dap[:x]) + y) % 7])