#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

int main() {
    fastio;
    int N, M;
    cin >> N >> M;

    if (N <= 2 || M == 0) {
        cout << "-1\n";
        return 0;
    }

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 1; i <= M; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }

    vector<bool> visited(N + 1, false);
    vector<vector<int>> components;
    vector<vector<int>> component_edges;

    // BFS to find all connected components
    for (int start = 1; start <= N; ++start) {
        if (visited[start]) continue;
        
        vector<int> component;
        vector<int> edges;
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        vector<int> parent(N + 1, -1);
        vector<int> edge_idx(N + 1, -1);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            component.push_back(current);
            
            for (auto [next, idx] : graph[current]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                    parent[next] = current;
                    edge_idx[next] = idx;
                    edges.push_back(idx);
                }
            }
        }
        components.push_back(component);
        component_edges.push_back(edges);
    }

    int num_components = components.size();
    
    // If we already have 2 components with different sizes, use them
    if (num_components == 2 && components[0].size() != components[1].size()) {
        vector<int> tree1_vertices = components[0];
        vector<int> tree1_edges = component_edges[0];
        vector<int> tree2_vertices = components[1];
        vector<int> tree2_edges = component_edges[1];

        cout << tree1_vertices.size() << " " << tree2_vertices.size() << "\n";
        for (int v : tree1_vertices) cout << v << " ";
        cout << "\n";
        for (int e : tree1_edges) cout << e << " ";
        cout << "\n";
        for (int v : tree2_vertices) cout << v << " ";
        cout << "\n";
        for (int e : tree2_edges) cout << e << " ";
        cout << "\n";
        return 0;
    } else if (num_components >= 2) {
        cout << "-1\n";
        return 0;
    }

    fill(visited.begin(), visited.end(), false);
    vector<int> bfs_order;
    vector<int> parent(N + 1, -1);
    vector<int> edge_idx(N + 1, -1);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfs_order.push_back(current);

        for (auto [next, idx] : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = current;
                edge_idx[next] = idx;
            }
        }
    }

    int last_vertex = bfs_order.back();
    vector<int> tree1_vertices;
    vector<int> tree2_vertices = {last_vertex};

    // All vertices except the last one go to the first tree
    for (int v : bfs_order) {
        if (v != last_vertex) {
            tree1_vertices.push_back(v);
        }
    }

    unordered_set<int> tree1_set(tree1_vertices.begin(), tree1_vertices.end());

    // Reconstruct the BFS spanning tree for the first tree
    vector<int> tree1_edges;
    for (int v : tree1_vertices) {
        if (v != 1) { // Skip the root
            int p = parent[v];
            if (tree1_set.count(p)) {
                tree1_edges.push_back(edge_idx[v]);
            }
        }
    }

    cout << tree1_vertices.size() << " " << tree2_vertices.size() << "\n";
    for (int v : tree1_vertices) cout << v << " ";
    cout << "\n";
    for (int e : tree1_edges) cout << e << " ";
    cout << "\n";
    for (int v : tree2_vertices) cout << v << " ";
    cout << "\n";

    // No edges for the second tree (single vertex)
    cout << "\n";

    return 0;
}
