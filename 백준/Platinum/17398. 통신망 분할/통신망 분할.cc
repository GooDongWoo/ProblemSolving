#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

int N, M, Q, cutA[100000];
LL ans;
pair<int, int> arr[100000];
unordered_set<int> cutS;

#define SIZE 100000
int parent[SIZE], childs[SIZE];

void init() {
	rep(i, 0, SIZE) {
		parent[i] = i;
		childs[i] = 1;
	}
}

int mfind(int num) {
	if (parent[num] != num) {
		parent[num] = mfind(parent[num]);
	}
	return parent[num];
}

void munion(int a, int b) {
	int pa = mfind(a);
	int pb = mfind(b);
	if (pa == pb) {
		return;
	}
	if (childs[pa] < childs[pb]) {
		swap(pa, pb);
	}
	childs[pa] += childs[pb];
	parent[pb] = pa;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cin >> N >> M >> Q;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		arr[i].first = a;
		arr[i].second = b;
	}
	rep(i, 0, Q) {
		int a;
		cin >> a;a--;
		cutS.insert(a);
		cutA[i] = a;
	}
	rep(i, 0, M) {
		if (cutS.count(i) == 0) {
			munion(arr[i].first, arr[i].second);
		}
	}
	rep(i, 0, Q) {
		int idx = cutA[Q - 1 - i];
		int pa, pb;
		pa = mfind(arr[idx].first);
		pb = mfind(arr[idx].second);
		if (pa == pb) {
			continue;
		}
		ans += ((LL)childs[pa]) * childs[pb];
		munion(arr[idx].first, arr[idx].second);
	}
	cout << ans;
	return 0;
}