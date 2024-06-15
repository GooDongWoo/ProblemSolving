import sys

T = int(sys.stdin.readline()) #Test case

for i in range(T):
        print(f" "*(T-(i+1))+f"*"*(i+1))