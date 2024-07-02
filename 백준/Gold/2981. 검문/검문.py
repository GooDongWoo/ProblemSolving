import sys
def GCD(a,b):
    min1=min(a,b)
    max1=max(a,b)
    if(max1%min1):
        return GCD(min1,max1%min1)
    else:
        return min1
def findPDiv(a):
    max_search=int(a**(1/2))+1
    result=[]
    for i in range(2,max_search):
        if(a%i==0):
            result.append(i)
            if(i**2 !=a):
                result.append(a//i)
    result.append(a)
    return sorted(result)

def main():        
    n=int(input())
    items=[0]*n
    for i in range(n):
        items[i]=int(sys.stdin.readline())
    items.sort()
    n_items=[0]*(n-1)
    
    for i in range(1,n):
        n_items[i-1]=items[i]-items[i-1]
    if(len(n_items)==1):
        mingcd=n_items[0]
    else:
        mingcd=GCD(n_items[0],n_items[1])
        for i in range(2,len(n_items)):
            mingcd=GCD(mingcd,n_items[i])
    print(*findPDiv(mingcd))
main()