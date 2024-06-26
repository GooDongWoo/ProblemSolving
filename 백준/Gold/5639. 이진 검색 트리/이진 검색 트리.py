import sys
sys.setrecursionlimit(int(1e9))
key_list=[]
def printPostorder(start,end):
    if(start==end):
        sys.stdout.write(f'{key_list[start]}\n')
        return
    elif(start<end):
        center=start
        r_s=end+1
        for i in range(start+1,end+1):
            if(key_list[i]>key_list[center]):
                r_s=i
                break
        printPostorder(start+1,r_s-1)
        printPostorder(r_s,end)
        sys.stdout.write(f'{key_list[start]}\n')
    else:
        return

while True:
    try:
        key_list.append(int(sys.stdin.readline().rstrip()))
    except:
        printPostorder(0,len(key_list)-1)
        break