import sys
input = sys.stdin.readline
print = sys.stdout.write

n_radix = int(input())




def isPrime(num):
    for i in range(2,num//2 +1):
        if (num%i==0):
            return False
    return True
                    
def DFS(cur_num,radix,candidate_n):
    if(radix == 0):
        print(f'{cur_num}\n')
        return
    
    cur_num*=10
    
    for target in candidate_n:
        nxt_num=cur_num + target    
        if (isPrime(nxt_num)):
            DFS(nxt_num,radix-1,[1,3,5,7,9])
        else:
            pass

DFS(0,n_radix,[2,3,5,7])