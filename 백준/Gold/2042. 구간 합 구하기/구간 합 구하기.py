import sys
sys.setrecursionlimit(int(1e9))
def segment(left, right, seg_idx):
    global n,m,k,nums,segment_tree
    if left == right:
        segment_tree[seg_idx] = nums[left]
        return segment_tree[seg_idx]
    mid = (right+left)//2
    segment_tree[seg_idx] = segment(left, mid, seg_idx*2) + segment(mid+1, right, seg_idx*2+1)
    return segment_tree[seg_idx]

def query_sum(start, end, searching_idx, target_l, target_r):
    global n,m,k,nums,segment_tree
    if target_l > end or target_r < start:
        return 0
    if target_l <= start and target_r >= end:
        return segment_tree[searching_idx]
    mid = (start + end) // 2
    return query_sum(start, mid, searching_idx*2, target_l, target_r) + query_sum(mid+1, end, searching_idx*2+1, target_l, target_r)

# 현재 노드의 포용범위 start, end
# 현재 노드 node
# 변경할 리프노드의 번호와 값 idx, val
def update(start, end, cur_s_idx, target_idx, val):
    global n,m,k,nums,segment_tree
    if start > target_idx or target_idx > end:
        return segment_tree[cur_s_idx]
    segment_tree[cur_s_idx] += val-nums[target_idx]
    if start != end:
        mid = (start + end) // 2
        update(start, mid, cur_s_idx*2, target_idx, val)
        update(mid+1, end, cur_s_idx * 2 +1, target_idx, val)

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
        print(query_sum(0, len(nums)-1, 1, b-1, c-1))