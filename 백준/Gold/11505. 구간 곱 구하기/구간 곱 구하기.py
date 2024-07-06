import sys
sys.setrecursionlimit(int(1e9))
modv=1000000007
def segment(left, right, seg_idx):
    global n,m,k,nums,segment_tree,modv
    if left == right:
        segment_tree[seg_idx] = nums[left]
        return segment_tree[seg_idx]

    mid = (right+left)//2
    segment_tree[seg_idx] = segment(left, mid, seg_idx*2) * segment(mid+1, right, seg_idx*2+1) % modv
    return segment_tree[seg_idx]

def query_product(start, end, seg_idx, target_l, target_r):
    global n,m,k,nums,segment_tree,modv
    if target_l > end or target_r < start:
        return 1
    if target_l <= start and target_r >= end:
        return segment_tree[seg_idx]
    mid = (start + end) // 2
    return query_product(start, mid, seg_idx*2, target_l, target_r) * query_product(mid+1, end, seg_idx*2+1, target_l, target_r) % modv

def update(start, end, seg_idx, target_idx, val):
    global n,m,k,nums,segment_tree,modv
    if start > target_idx or target_idx > end:
        return segment_tree[seg_idx]
    
    if(start == end):
        segment_tree[seg_idx]=val
        return segment_tree[seg_idx]
    else:
        mid = (start + end) // 2
        segment_tree[seg_idx]=update(start, mid, seg_idx*2, target_idx, val) * update(mid+1, end, seg_idx * 2 +1, target_idx, val) % modv
        return segment_tree[seg_idx]

n,m,k=map(int,sys.stdin.readline().split())
nums=[]
for _ in range(n):
    nums.append(int(sys.stdin.readline()))

# H = ceil(log(len(nums), 2)+1)
# tree_size = pow(2, H+1) - 1
segment_tree = [0]*len(nums)*4
segment(0, len(nums)-1, 1)
for _ in range(m+k):
    a,b,c=map(int,sys.stdin.readline().split())
    if(a==1):#update
        update(0, len(nums)-1, 1, b-1, c)
        nums[b-1]=c
    else:#query
        print(int(query_product(0, len(nums)-1, 1, b-1, c-1)))