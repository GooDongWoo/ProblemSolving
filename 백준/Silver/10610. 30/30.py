import sys
words=[*map(int,list(sys.stdin.readline().rstrip()))]
if((sum(words)%3==0) and (0 in words) and len(words)>1):
    words.sort(reverse=True)
    print(''.join(map(str,words)))
else:
    print(-1)