'''
예제 입력 1 
80
99
예제 출력 1 
high speed rail
예제 입력 2 
99
98
예제 출력 2 
flight
'''
a = [int(input()) for _ in range(2)]
if(a[0]>a[1]):
    print("flight")
else:
    print("high speed rail")