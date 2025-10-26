#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, K, arr[10000],ans;
vector<int> cs;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> K;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	N = unique(arr, arr + N) - arr;
	K = min(N, K);
	rep(i, 1, N) {
		cs.push_back(arr[i] - arr[i - 1]);
	}
	sort(cs.begin(), cs.end());
	rep(i, 0, cs.size() - K + 1) {
		ans += cs[i];
	}
	cout << ans;
	return 0;
}