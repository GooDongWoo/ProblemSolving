n,m = map(int, input().split())
tree_list=list(map(int,input().split()))
tree_list.sort(reverse=True) #내림차순
sum_list=[0]*len(tree_list)
sum_list[0]=tree_list[0]
res=0
idx=-1
if(n==1):
    print(tree_list[0]-m)
else:
    for i in range(1,len(tree_list)):
        sum_list[i] = sum_list[i-1] + tree_list[i]
        res = sum_list[i]-(tree_list[i]*(i+1))
        if(res>=m):
            idx=i
            break
    if (res==m):
        #good
        print(tree_list[idx])
    elif (idx != -1):
        #reverse traversal
        x=int((sum_list[idx-1]-m)/idx)
        print(x)
    else:
        x=int((sum_list[len(tree_list)-1]-m)/len(tree_list))
        print(x)