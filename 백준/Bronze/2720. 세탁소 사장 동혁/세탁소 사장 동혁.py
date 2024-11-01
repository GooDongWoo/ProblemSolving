import sys
input=sys.stdin.readline

n = int(input())

for _ in range(n):
	leftmoney = int(input())
	for i in [25, 10, 5, 1]:
		print(leftmoney//i, end=' ')
		leftmoney = leftmoney%i