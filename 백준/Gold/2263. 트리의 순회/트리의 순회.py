import sys
sys.setrecursionlimit(10**8)
def preorder(inO_s, inO_e, postO_s, postO_e):
    if(inO_s > inO_e) or (postO_s > postO_e):
        return
    
    root = postorder[postO_e]
    sys.stdout.write(f'{root} ')
    
    left_num = inO_idx_list[root] - inO_s
    preorder(inO_s, inO_s+left_num-1, postO_s, postO_s+left_num-1) 
    preorder(inO_s+left_num+1, inO_e, postO_s+left_num, postO_e-1) 
    
n = int(sys.stdin.readline())
inorder = list(map(int, sys.stdin.readline().split()))
postorder = list(map(int, sys.stdin.readline().split()))
inO_idx_list = [0 for _ in range(n+1)]
for i in range(n):
    inO_idx_list[inorder[i]] = i
preorder(0, n-1, 0, n-1)