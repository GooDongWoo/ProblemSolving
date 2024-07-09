words=[0]*5
for i in range(5):
    words[i]=list(input().rstrip())

for i in range(15):
    for j in range(5):
        if(i>=len(words[j])):
            continue
        else:
            print(words[j][i],end='')