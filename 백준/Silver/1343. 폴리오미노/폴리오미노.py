import sys
words=sys.stdin.readline().rstrip()
words=words.replace('XXXX','AAAA')
words=words.replace('XX','BB')
print(-1) if('X' in words) else print(words)