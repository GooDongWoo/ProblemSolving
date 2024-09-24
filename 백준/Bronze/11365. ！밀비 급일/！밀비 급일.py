while 1:
    words=input().rstrip()
    if(words=='END'):
        break
    print(words[::-1])