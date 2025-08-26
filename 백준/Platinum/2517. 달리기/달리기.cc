#include <iostream>
#include <algorithm>
#include <unordered_map>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[500001], o1[500001], o2[500001];
unordered_map<int, int> dict;

void update(int idx, int val) {
	while (idx <= N) {
		arr[idx] += val;
		idx += idx & (~idx + 1);
	}
}

int query(int idx) {
	int cur = 0;
	while (idx > 0) {
		cur += arr[idx];
		idx -= idx & (~idx + 1);
	}
	return cur;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	dict.reserve(N);
	rep(i, 1, N + 1) {
		cin >> o1[i];
		o2[i] = o1[i];
	}
	sort(o2 + 1, o2 + N + 1);
	rep(i, 1, N + 1) {
		dict[o2[i]] = i;
	}
	rep(i, 1, N + 1) {
		cout << (i - query(dict[o1[i]])) << '\n';
		update(dict[o1[i]], 1);
	}
	return 0;
}