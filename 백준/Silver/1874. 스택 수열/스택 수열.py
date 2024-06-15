from sys import stdin,stdout
input=stdin.readline
print=stdout.write

s_size=int(input())
ans_list=[]
stck=[]
minus_cnt=0
# push the number from 1 to first input number
input_num=int(input())
for i in range(1,input_num+1):
    stck.append(i)
    ans_list.append("+\n")
    
pointer=input_num+1  
stck.pop()
ans_list.append("-\n")
minus_cnt+=1
if s_size==1:
    for i in range(len(ans_list)):
        print(ans_list[i])
    exit()
if len(stck)==0:
    bef_num=0
else:
    bef_num=stck[-1]    
#print(f"first state: {str(stck)}\n")
while 1:
    input_num=int(input())
    # if next number is bigger than before number, we continue pushing
    if input_num > bef_num:
        while pointer<=input_num:
            stck.append(pointer)
            ans_list.append("+\n")
            #print(f"stck status: {str(stck)}\n")    #option
            pointer+=1
        
        stck.pop()
        ans_list.append("-\n")
        minus_cnt+=1
        #print(f"stck status: {str(stck)}\n")
        
    # else next number is smaller than before number, we check second from the back and last one. if input number is the second frome the back, this would be ok, but if not, print NO    
    elif input_num == bef_num:
        stck.pop()
        ans_list.append("-\n")
        minus_cnt+=1  
        #print(f"stck status: {str(stck)}\n")    #option
    else:                   
        print("NO")
        break
    try:
        bef_num=stck[-1]
    except:
        if minus_cnt==s_size:
            for i in range(len(ans_list)):
                print(ans_list[i])
            break
    