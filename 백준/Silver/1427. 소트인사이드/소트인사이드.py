num_input=list(input())
num_input.sort(reverse=True)
tmp=''
for s in num_input:
    tmp+=s
print(f'{int(tmp)}')