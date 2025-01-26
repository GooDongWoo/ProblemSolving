import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5))
class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 0, 0, self.n-1)
    
    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = (arr[start], start)
            return
        
        mid = (start + end) // 2
        self.build(arr, 2*node+1, start, mid)
        self.build(arr, 2*node+2, mid+1, end)
        
        left = self.tree[2*node+1]
        right = self.tree[2*node+2]
        self.tree[node] = left if left[0] <= right[0] else right

    def query(self, node, start, end, left, right):
        if right < start or end < left:
            return (float('inf'), -1)
        if left <= start and end <= right:
            return self.tree[node]
            
        mid = (start + end) // 2
        left_result = self.query(2*node+1, start, mid, left, right)
        right_result = self.query(2*node+2, mid+1, end, left, right)
        return left_result if left_result[0] <= right_result[0] else right_result

def largest_rectangle(heights):
    def calculate_area(start, end):
        if start > end:
            return 0
        if start == end:
            return heights[start]
            
        min_height, min_idx = st.query(0, 0, n-1, start, end)
        area = min_height * (end - start + 1)
        
        left_area = calculate_area(start, min_idx-1)
        right_area = calculate_area(min_idx+1, end)
        
        return max(area, left_area, right_area)
    
    n = len(heights)
    st = SegmentTree(heights)
    return calculate_area(0, n-1)

while 1:
    raws = input().rstrip()
    if (raws[0] == '0'):break
    n, *a = map(int, raws.split())
    print(largest_rectangle(a))