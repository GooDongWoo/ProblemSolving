#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 100005;
const int LOGN = 17; // log2(100000) + 1

int N, K;
vector<vector<pair<int, int>>> adj;
int parent[LOGN][MAXN], minEdge[LOGN][MAXN], maxEdge[LOGN][MAXN];
int depth[MAXN];

inline void dfs(int u, int p, int d) {
    depth[u] = d;
    parent[0][u] = p;
    
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v != p) {
            minEdge[0][v] = maxEdge[0][v] = w;
            dfs(v, u, d + 1);
        }
    }
}

inline void preprocess() {
    // Binary lifting 전처리 - 메모리 접근 패턴 최적화
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < N; i++) {
            int p = parent[j-1][i];
            if (p != -1) {
                parent[j][i] = parent[j-1][p];
                minEdge[j][i] = min(minEdge[j-1][i], minEdge[j-1][p]);
                maxEdge[j][i] = max(maxEdge[j-1][i], maxEdge[j-1][p]);
            }
        }
    }
}

inline pair<int, int> query(int u, int v) {
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    if (depth[u] < depth[v]) {
        int temp = u; u = v; v = temp; // swap 최적화
    }
    
    // u를 v와 같은 깊이로 맞추기 - 비트 연산 최적화
    int diff = depth[u] - depth[v];
    for (int i = 0; diff; i++, diff >>= 1) {
        if (diff & 1) {
            minVal = min(minVal, minEdge[i][u]);
            maxVal = max(maxVal, maxEdge[i][u]);
            u = parent[i][u];
        }
    }
    
    if (u == v) return {minVal, maxVal};
    
    // LCA 찾기 - 역순으로 최적화
    for (int i = LOGN - 1; i >= 0; i--) {
        int pu = parent[i][u], pv = parent[i][v];
        if (pu != pv) {
            int minU = minEdge[i][u], minV = minEdge[i][v];
            int maxU = maxEdge[i][u], maxV = maxEdge[i][v];
            
            minVal = min(minVal, min(minU, minV));
            maxVal = max(maxVal, max(maxU, maxV));
            u = pu; v = pv;
        }
    }
    
    // 마지막 단계
    minVal = min(minVal, min(minEdge[0][u], minEdge[0][v]));
    maxVal = max(maxVal, max(maxEdge[0][u], maxEdge[0][v]));
    
    return {minVal, maxVal};
}

int main() {
    scanf("%d", &N);
    adj.resize(N);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    // 초기화 최적화
    for (int i = 0; i < LOGN; i++) {
        for (int j = 0; j < N; j++) {
            parent[i][j] = -1;
            minEdge[i][j] = INT_MAX;
            maxEdge[i][j] = INT_MIN;
        }
    }
    
    dfs(0, -1, 0);
    preprocess();
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        auto result = query(u, v);
        printf("%d %d\n", result.first, result.second);
    }
    
    return 0;
}