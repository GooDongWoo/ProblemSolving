import sys
sys.setrecursionlimit(100000)
class node():
    def __init__(self) -> None:
        self.child=[]
        self.parent=''

node_num=int(input())
node_list=[node() for _ in range(node_num+1)]
adj_mat=[[] for _ in range(node_num+1)]
visited=[0]*(node_num+1)
for _ in range(node_num-1):
    a,b=map(int,sys.stdin.readline().split())
    adj_mat[a].append(b)
    adj_mat[b].append(a)

#line nodes

def lineNode(p_num):
    global adj_mat,node_list
    c_of_p_list=adj_mat[p_num]
    p_node=node_list[p_num]
    visited[p_num]=1
    for child_num in c_of_p_list:
        if(visited[child_num]==0):
            p_node.child.append(child_num)
            node_list[child_num].parent=p_num
            lineNode(child_num)
    
lineNode(1)        

for i in range(2,len(node_list)):
    print(node_list[i].parent)
    




