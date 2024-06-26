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

#객체로 구현하니 시간 초과 나옴... 그래서 그냥 배열로 풀었다..
'''
import sys
sys.setrecursionlimit(int(1e9))
class Node():
    def __init__(self,value) -> None:
        self.key=value
        self.left=None
        self.right=None

root=Node(None)
def addNode(key,parent=root):
    if not (parent.key):#init val
        parent.key=key
    else:#normal add process
        if(key<parent.key):#go left
            if not(parent.left):
                parent.left=Node(key)
            else:
                addNode(key,parent.left)
        else:
            if not(parent.right):
                parent.right=Node(key)
            else:
                addNode(key,parent.right)

def postorder(root):
    if(root.left):
        postorder(root.left)
    if(root.right):
        postorder(root.right)
    sys.stdout.write(f'{root.key}\n')

while True:
    try:
        key= int(sys.stdin.readline())
        addNode(key)
    except:
        postorder(root)
        break
'''

'''tree=[0]*10001
def makeTree(key,parent=1):
    global tree
    if not (tree[1]):
        tree[1]=key
    else:#normal add process
            if(key<tree[parent]):#go left
                if not(tree[2*parent]):
                    tree[2*parent]=key
                else:
                    makeTree(key,2*parent)
            else:
                if not(tree[2*parent +1]):
                    tree[2*parent +1]=key
                else:
                    makeTree(key,2*parent +1)


def postorder(root):
    if(root.left):
        postorder(root.left)
    if(root.right):
        postorder(root.right)
    sys.stdout.write(f'{root.key}\n')
'''