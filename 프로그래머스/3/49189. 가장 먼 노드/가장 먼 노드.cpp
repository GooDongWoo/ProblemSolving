#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> adj_v(n); queue <int> q; vector <int> v(n);
    int p,cnt=0; vector <int> res; int tmp;
    for (int i=0;i<edge.size();i++){
        adj_v[edge[i][0]-1].push_back(edge[i][1]-1);
        adj_v[edge[i][1]-1].push_back(edge[i][0]-1);
    }
    q.push(0);v[0]=1;
    while (not q.empty()){
        cnt=0;tmp=q.size();
        for (int i=0;i<tmp;i++){
            p=q.front();q.pop();
            for (auto c: adj_v[p]){
                if(v[c]==0){
                    q.push(c);v[c]=1;cnt++;
                }
            }       
        }
        res.push_back(cnt);
    }
    
    return res[res.size()-2];
}