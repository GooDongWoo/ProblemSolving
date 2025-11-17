n = int(input())
k = int(input()) + 60
print(max(n - k, 0)*3000+min(k,n)*1500)