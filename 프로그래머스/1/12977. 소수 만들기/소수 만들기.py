def solution(nums):
    maximum=3000
    primes=[1]*(maximum+1)
    primes[0]=primes[1]=0
    for i in range(2,maximum+1):
        if(primes[i]):
            idx=2
            while idx*i<=maximum:
                primes[idx*i]=0
                idx+=1
    answer = 0            
    for i in range(len(nums)-2):
        for j in range(i+1,len(nums)-1):
            for k in range(j+1,len(nums)):
                if(primes[nums[i]+nums[j]+nums[k]]):
                    answer+=1
    return answer