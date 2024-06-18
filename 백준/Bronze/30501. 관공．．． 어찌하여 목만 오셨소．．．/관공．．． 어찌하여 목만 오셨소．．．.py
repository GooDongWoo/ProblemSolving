n=int(input())
target_list=[]
for i in range(n):
    target_list.append(input().rstrip())
    if( 'S' in target_list[i]):
        print(target_list[i])