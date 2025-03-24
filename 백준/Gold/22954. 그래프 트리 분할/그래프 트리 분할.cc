#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>
#include <unordered_set>

using namespace std;

int main() {
	fastio;

	int N, M;
	cin >> N >> M;

	if (N <= 2 || M == 0) {
		printf("-1\n");
		return 0;
	}

	vector<vector<pair<int, int>>> graph(N + 1);

	rep(i, 1, M + 1) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back({ v, i });
		graph[v].push_back({ u, i });
	}

	vector<bool> visited(N + 1, false);
	vector<vector<int>> components;
	vector<vector<int>> component_edges;

	rep(start, 1, N + 1) {
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

		printf("%d %d\n", (int)tree1_vertices.size(), (int)tree2_vertices.size());

		for (int v : tree1_vertices) {
			printf("%d ", v);
		}
		printf("\n");

		for (int e : tree1_edges) {
			printf("%d ", e);
		}
		printf("\n");

		for (int v : tree2_vertices) {
			printf("%d ", v);
		}
		printf("\n");

		for (int e : tree2_edges) {
			printf("%d ", e);
		}
		printf("\n");

		return 0;
	}
	else if (num_components >= 2) {
		printf("-1\n");
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
	vector<int> tree2_vertices = { last_vertex };

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

	printf("%d %d\n", (int)tree1_vertices.size(), (int)tree2_vertices.size());

	for (int v : tree1_vertices) {
		printf("%d ", v);
	}
	printf("\n");

	for (int e : tree1_edges) {
		printf("%d ", e);
	}
	printf("\n");

	for (int v : tree2_vertices) {
		printf("%d ", v);
	}
	printf("\n");

	// No edges for the second tree (single vertex)
	printf("\n");

	return 0;
}