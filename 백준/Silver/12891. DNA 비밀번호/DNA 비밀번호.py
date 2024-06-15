dna_size, sub_dna_size=map(int,input().split())
dna_list=input()
a_thres,c_thres,g_thres,t_thres=map(int, input().split())

item_number=[0,0,0,0]
for i in range(sub_dna_size):
    if dna_list[i]=='A':
        item_number[0]+=1
    elif dna_list[i] == 'C':
        item_number[1]+=1
    elif dna_list[i] == 'G':
        item_number[2]+=1
    elif dna_list[i] == 'T':
        item_number[3]+=1
    else:
        raise ValueError    

cnt=0
for i in range(dna_size-sub_dna_size+1):
    #check the threshold and plus the cnt
    if item_number[0] >= a_thres and item_number[1] >= c_thres and item_number[2] >= g_thres and item_number[3] >= t_thres :
        cnt+=1
    #refresh the numbers
    if dna_list[i]=='A':
        item_number[0]-=1
    elif dna_list[i] == 'C':
        item_number[1]-=1
    elif dna_list[i] == 'G':
        item_number[2]-=1
    elif dna_list[i] == 'T':
        item_number[3]-=1
    else:
        raise ValueError
    try:
        if dna_list[i+sub_dna_size]=='A':
            item_number[0]+=1
        elif dna_list[i+sub_dna_size] == 'C':
            item_number[1]+=1
        elif dna_list[i+sub_dna_size] == 'G':
            item_number[2]+=1
        elif dna_list[i+sub_dna_size] == 'T':
            item_number[3]+=1
    except:
        pass
print(cnt)