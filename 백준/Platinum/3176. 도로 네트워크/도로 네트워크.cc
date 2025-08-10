#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int LOGN = 17;
const int INF = 1e9;

int N, K;
vector<pair<int, int>> adj[MAXN];
int up[LOGN][MAXN], minw[LOGN][MAXN], maxw[LOGN][MAXN];
int depth[MAXN];

// 비트 연산으로 최고차 비트 찾기 (훨씬 빠름)
inline int highestBit(int x) {
    return 31 - __builtin_clz(x);
}

void dfs(int u, int p) {
    up[0][u] = p;
    for (auto& edge : adj[u]) {
        int v = edge.first, w = edge.second;
        if (v != p) {
            depth[v] = depth[u] + 1;
            minw[0][v] = maxw[0][v] = w;
            dfs(v, u);
        }
    }
}

void preprocess() {
    // 한 번에 모든 레벨 계산 - 캐시 친화적
    for (int j = 1; j < LOGN; j++) {
        for (int i = 0; i < N; i++) {
            int mid = up[j-1][i];
            if (mid != -1) {
                up[j][i] = up[j-1][mid];
                minw[j][i] = min(minw[j-1][i], minw[j-1][mid]);
                maxw[j][i] = max(maxw[j-1][i], maxw[j-1][mid]);
            }
        }
    }
}

// 핵심 최적화: 불필요한 분기와 중복 계산 제거
pair<int, int> lca_query(int u, int v) {
    int minval = INF, maxval = -INF;
    
    if (depth[u] < depth[v]) swap(u, v);
    
    // 1. 깊이 맞추기 - 비트 연산으로 한 번에
    int diff = depth[u] - depth[v];
    while (diff) {
        int bit = highestBit(diff);  // 최고차 비트를 O(1)에 찾기
        minval = min(minval, minw[bit][u]);
        maxval = max(maxval, maxw[bit][u]);
        u = up[bit][u];
        diff ^= (1 << bit);  // 해당 비트 제거
    }
    
    if (u == v) return {minval, maxval};
    
    // 2. LCA 찾기 - 역순으로 단 한 번만
    for (int i = LOGN - 1; i >= 0; i--) {
        int uu = up[i][u], vv = up[i][v];
        if (uu != vv) {
            // 지역 변수로 메모리 접근 최소화
            int minu = minw[i][u], minv = minw[i][v];
            int maxu = maxw[i][u], maxv = maxw[i][v];
            
            minval = min(minval, min(minu, minv));
            maxval = max(maxval, max(maxu, maxv));
            u = uu; v = vv;
        }
    }
    
    // 3. 마지막 단계 - 한 번만
    minval = min(minval, min(minw[0][u], minw[0][v]));
    maxval = max(maxval, max(maxw[0][u], maxw[0][v]));
    
    return {minval, maxval};
}

int main() {
    scanf("%d", &N);
    
    // 초기화 최적화
    for (int i = 0; i < LOGN; i++) {
        for (int j = 0; j < N; j++) {
            up[i][j] = -1;
            minw[i][j] = INF;
            maxw[i][j] = -INF;
        }
    }
    
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--; b--;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    depth[0] = 0;
    dfs(0, -1);
    preprocess();
    
    scanf("%d", &K);
    while (K--) {  // for문보다 while이 약간 빠름
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        auto result = lca_query(u, v);
        printf("%d %d\n", result.first, result.second);
    }
    
    return 0;
}