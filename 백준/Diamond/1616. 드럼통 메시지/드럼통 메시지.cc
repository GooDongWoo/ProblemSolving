#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    int K, M;
    cin >> K >> M;
    if (M == 1) {
        for (int i = 0; i < K; ++i) {
            cout << i << " ";
        }
        return 0;
    }

    int num_vertices = pow(K, M - 1);
    int p = pow(K, M - 2);
    vector<int> edges_taken(num_vertices);
    vector<int> path;
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top();
        if (edges_taken[u] < K) {
            int k = edges_taken[u];
            edges_taken[u]++;
            int v = (u % p) * K + k;
            st.push(v);
        }
        else {
            st.pop();
            path.push_back(u % K);
        }
    }
    for (size_t i = 0; i < path.size() - 1; ++i) {
        cout << path[i] << " ";
    }
    return 0;
}