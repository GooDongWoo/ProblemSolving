word=input().rstrip()
l1=[]
for i in range(1,13):
    l1.append(('w'*i)+('o'*i)+('l'*i)+('f'*i))
for w in l1:
    word=word.replace(w,'_')

flag=1
for i in range(len(word)):
    if(word[i]!='_'):
        print(0)
        flag=0
        break
if(flag):
    print(1)