n=int(input().strip())
t_list=list(map(int,input().split()))
t,p=map(int,input().split())

t_bundle_list=[0]*6
for idx in range(len(t_bundle_list)):
    t_bundle_list[idx]=t_list[idx]//t if t_list[idx]%t==0 else (t_list[idx]//t)+1
print(sum(t_bundle_list))
print(n//p,n%p)