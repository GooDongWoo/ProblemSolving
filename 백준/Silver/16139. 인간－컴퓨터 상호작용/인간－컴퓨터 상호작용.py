import sys
word=sys.stdin.readline().rstrip()
cnter_dict=[[0]*26 for _ in range(len(word))]

cnter_dict[0][ord(word[0])-ord('a')]=1
for i in range(1,len(word)):
    cnter_dict[i]=cnter_dict[i-1][:]
    cnter_dict[i][ord(word[i])-ord('a')]+=1

q=int(sys.stdin.readline())
for _ in range(q):
    tar,start,end=sys.stdin.readline().split()
    start,end=int(start),int(end)
    chck=(ord(tar)-ord('a'))
    sub=0 if start==0 else cnter_dict[start-1][chck]
    print(cnter_dict[end][chck]-sub)