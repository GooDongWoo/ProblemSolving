#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>

int N;
int adj[1001][1001];
int search_from[1001] = {};

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        int degree = 0;
        for (int j = 0; j < N; ++j) {
            scanf("%d", &adj[i][j]);
            degree += adj[i][j];
        }
        if (degree % 2 != 0) {
            printf("-1\n");
            return 0;
        }
    }

    std::vector<int> path;
    std::stack<int> st;

    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        bool found_edge = false;

        for (int& v = search_from[u]; v <= N; ++v) {
            if (v == N) {
                break;
            }
            if (adj[u][v] > 0) {
                found_edge = true;
                
                adj[u][v]--;
                adj[v][u]--;
                
                st.push(v);
                break;
            }
        }

        if (!found_edge) {
            st.pop();
            path.push_back(u);
        }
    }

    std::reverse(path.begin(), path.end());

    for (int node : path) {
        printf("%d ", node + 1);
    }
    printf("\n");

    return 0;
}