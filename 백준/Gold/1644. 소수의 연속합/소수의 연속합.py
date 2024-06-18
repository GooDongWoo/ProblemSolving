import sys
def prime_numbers(n):
    number_list = [i for i in range(n+1)] 
    end = int(n**(1/2))
    for i in range(2, end+1):
        if number_list[i] == 0:
            continue
        for j in range(i**2, n+1, i):
            number_list[j] = 0
    return [i for i in number_list[2:] if number_list[i]]

inf=int(1e8)
n=int(sys.stdin.readline())
prime_list=prime_numbers(n)
sum_list=[0]*(len(prime_list)+1)
for idx in range(1,len(sum_list)):
    sum_list[idx]=sum_list[idx-1]+prime_list[idx-1]
cnt=0
start=0
end=1
while(end<len(sum_list)):
    if(sum_list[end]-sum_list[start]<n):#end를 늘려서 될때까지 늘린다.
        end+=1
    elif(sum_list[end]-sum_list[start]>n):
        start+=1
    elif(sum_list[end]-sum_list[start]==n):
        cnt+=1
        end+=1
sys.stdout.write(f'{cnt}') if cnt!=inf else sys.stdout.write(f'0')