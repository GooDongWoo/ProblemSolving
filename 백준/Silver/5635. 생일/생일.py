n=int(input())
list1=[]
for _ in range(n):
    name,day,month,year=input().split()
    list1.append(tuple([int(year),int(month),int(day),name]))
list1.sort(key=lambda x:(x[0],x[1],x[2]))
print(list1[-1][3])
print(list1[0][3])