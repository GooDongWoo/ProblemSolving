import sys
import heapq
n=int(sys.stdin.readline())
card_list=[int(sys.stdin.readline()) for _ in range(n)]
heapq.heapify(card_list)
res=0
while len(card_list)>=2:
    s1=heapq.heappop(card_list)
    s2=heapq.heappop(card_list)
    heapq.heappush(card_list,s1+s2)
    res+=s1+s2
print(res)