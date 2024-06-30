import sys
n=int(sys.stdin.readline())
word_list=[list(sys.stdin.readline().rstrip()) for _ in range(n)]

total_char_set=set()
for word in word_list:
    for char in word:
        total_char_set.add(char)
word_list.sort(key=lambda x:len(x),reverse=True)
max_len=len(word_list[0])
for i in range(1,n):
    word_list[i]=['' for _ in range(max_len-len(word_list[i]))]+word_list[i]

radix_alphab_cnt=[0 for _ in range(26)]
for radix in range(max_len-1,-1,-1):
    for word in word_list:
        if(word[radix]):
            radix_alphab_cnt[ord(word[radix])-ord('A')]+=(10**(max_len-1-radix))

radix_alphab_cnt.sort(reverse=True)

res=0
num=9
for cnter in radix_alphab_cnt:
    res+=num*cnter
    num-=1
print(res)




'''
matching_dict=dict()
for char in total_char_set:
    matching_dict[char]=-1
    
    
def compareList(list1,list2):
    leng1=len(list1)
    leng2=len(list2)
    cmpr_max=min(leng1,leng2)
    for i in range(cmpr_max):
        if(list1[i]>list2[i]):
            return True
        elif(list1[i]<list2[i]):
            return False
        else:
            pass'''