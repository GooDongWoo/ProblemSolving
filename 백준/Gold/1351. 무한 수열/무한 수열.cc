#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <unordered_map>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

LL N, P, Q;
unordered_map<LL, LL> dict;

LL F(LL val) {
	if (val == 0) return 1;
	if (dict.count(val) == 0) {
		LL ret1 = F(val / P);
		LL ret2 = F(val / Q);
        dict[val] = ret1 + ret2;
		return dict[val];
	}
	else {
		return dict[val];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> P >> Q;

	cout << F(N);

	return 0;
}