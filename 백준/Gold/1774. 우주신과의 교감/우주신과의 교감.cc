#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

struct Item {
	double w;
	int a, b;
	bool operator>(const Item& b) const {
		return w > b.w;
	}
};

int N, M, parent[1000], nchild[1000];
pair<int, int> arr[1000];
double ans;

int Find(int a) {
	if (parent[a] != a) {
		parent[a] = Find(parent[a]);
	}
	return parent[a];
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) {
		return;
	}
	if (nchild[pa] < nchild[pb]) {
		swap(pa, pb);
	}
	parent[pb] = pa;
	nchild[pa] += nchild[pb];
	return;
}

template<typename T>
double GetDist(pair<T, T>& a, pair<T, T>& b) {
	double val = ((double)(a.first - b.first)) * ((double)(a.first - b.first)) + ((double)(a.second - b.second)) * ((double)(a.second - b.second));
	return sqrt(val);
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> M;
	rep(i, 0, N) {
		cin >> arr[i].first >> arr[i].second;
		parent[i] = i;
		nchild[i] = 1;
	}

	priority_queue<Item, vector<Item>, greater<>> pq;
	rep(i, 0, N) {
		rep(j, i + 1, N) {
			double cdist = GetDist(arr[i], arr[j]);
			pq.push({ cdist,i,j });
		}
	}

	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		Union(a, b);
	}
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		double cw = curp.w;
		int a = curp.a, b = curp.b;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		ans += cw;
	}
	printf("%.2lf\n", round(ans * 100) / 100);
	return 0;
}