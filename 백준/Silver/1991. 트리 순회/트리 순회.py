import sys
print=sys.stdout.write
class node():
    def __init__(self,name='',left='',right='') -> None:
        self.name=name
        self.left=left
        self.right=right
def translateName2Nodeidx(name):
    if(name=='.'):
        return -1
    first=ord("A")
    target=ord(name)
    return target-first
def preorder(node):
    #code
    print(node.name)
    #left
    if(node.left !='.'):
        preorder(node_list[translateName2Nodeidx(node.left)])
    #right
    if(node.right !='.'):
        preorder(node_list[translateName2Nodeidx(node.right)])
def inorder(node):
    #left
    if(node.left !='.'):
        inorder(node_list[translateName2Nodeidx(node.left)])
    #code
    print(node.name)
    #right
    if(node.right !='.'):
        inorder(node_list[translateName2Nodeidx(node.right)])
def postorder(node):
    #left
    if(node.left !='.'):
        postorder(node_list[translateName2Nodeidx(node.left)])
    #right
    if(node.right !='.'):
        postorder(node_list[translateName2Nodeidx(node.right)])
    #code
    print(node.name)
    
node_num=int(input())
node_list=[node(name=chr(ord('A')+i)) for i in range(node_num)] #A:0,B:1,C:2,D:3,E:4...
#initialize
for i in range(node_num):
    name,left,right=sys.stdin.readline().split()
    node_list[ord(name)-ord('A')].left=left
    node_list[ord(name)-ord('A')].right=right

preorder(node_list[0])
print(f'\n')
inorder(node_list[0])
print(f'\n')
postorder(node_list[0])