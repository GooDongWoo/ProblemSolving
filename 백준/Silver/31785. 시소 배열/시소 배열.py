import sys
input=sys.stdin.readline

MAX = 500000
q = int(input())
start = 0
end = 1
arr =[0] * (MAX + 1)
for _ in range(q):
    raw_data = input().rstrip()
    if (raw_data[0] == '1'):
        _, val = raw_data.split()
        val = int(val)
        arr[end] = val + arr[end - 1]
        end += 1
    else:
        mid = (start + end - 1) // 2
        bef_sum = arr[mid] - arr[start]
        aft_sum = arr[end - 1] - arr[mid]
        if bef_sum <= aft_sum:
            sys.stdout.write(f'{bef_sum}\n')
            start = mid
        else:
            sys.stdout.write(f'{aft_sum}\n')
            end = mid + 1

for i in range(start + 1, end):
    sys.stdout.write(f'{arr[i] - arr[i - 1]} ')