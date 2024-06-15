import sys
input=sys.stdin.readline
print=sys.stdout.write

n_node=int(input())
cut =0
#adj_m=[[cut for _ in range(n_node+1)] for _ in range(n_node+1)] # (n_node+1) X (n_node+1) # 기존 인접 매트릭스... 메모리 초과
adj_m=[[] for _ in range(n_node+1)]
visited=[0]*(n_node+1)
max_len=0
end_point=0


for i in range(1,n_node+1):
    tmp_list= list(map(int,input().split()))
    row=tmp_list[0]
    col=tmp_list[1:-1:2]
    val=tmp_list[2:-1:2]
    for a,b in zip(col,val):
        adj_m[row].append((a,b))
    adj_m[row].sort(key = lambda x: x[1],reverse=True)

def dfs(start,length):# initial length is 0
    global adj_m,visited,max_len,end_point
    tmp=[]
    visited[start]=1
    #먼저 그 해당 노드에 연결된 간선(0보다는 큰 간선들만)들을 정렬하고 리스트에 순서대로 넣는다.
    for node, value in (adj_m[start]):
        if ((value>0) and (visited[node]==0)):
            tmp.append((node,value))
    
    # 큰 엣지들마다
    for NodeValue in tmp:
        if(visited[NodeValue[0]]==0):
            visited[NodeValue[0]]=1
            dfs(NodeValue[0],length+NodeValue[1])
    if(length==max(max_len,length)):
        max_len=length
        end_point=start
dfs(i,0)
visited=[0]*(n_node+1)
dfs(end_point,0)
print(f'{max_len}')