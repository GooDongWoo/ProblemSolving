class SegmentTree:
   def __init__(self, arr):
       self.n = len(arr)
       self.tree = [0] * (4 * self.n)
       self.build(arr, 1, 0, self.n - 1)
       
   def build(self, arr, node, start, end):
       if start == end:
           self.tree[node] = arr[start]
           return
       mid = (start + end) >> 1
       self.build(arr, node * 2, start, mid)
       self.build(arr, node * 2 + 1, mid + 1, end)
       self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]
       
   def query(self, arr, node, start, end, left, right):
       if right < start or end < left:
           return 0
       if left <= start and end <= right:
           return self.tree[node]
       mid = (start + end) >> 1
       return (self.query(arr, node * 2, start, mid, left, right) + 
               self.query(arr, node * 2 + 1, mid + 1, end, left, right))
   
   def update(self, arr, node, start, end, index, val):
       if index < start or index > end:
           return
       if start == end:
           arr[index] += val
           self.tree[node] = arr[index]
           return
       mid = (start + end) >> 1
       self.update(arr, node * 2, start, mid, index, val)
       self.update(arr, node * 2 + 1, mid + 1, end, index, val)
       self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

n, q = map(int, input().split())
arr = [0] * n
st = SegmentTree(arr)

for _ in range(q):
   typ, b, e = map(int, input().split())
   if typ == 1:
       st.update(arr, 1, 0, n-1, b-1, e)
   else:
       print(st.query(arr, 1, 0, n-1, b-1, e-1))