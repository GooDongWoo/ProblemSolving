#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, M,ans;
vector<pair<int, int>> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	int cur = 0;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b;
		cur += a;
		arr.push_back({ cur,b });
	}
	cur = 0;
	int idx = 0;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		cur += a;
		while (idx < N && arr[idx].first < cur) {
			ans = max(ans, b-arr[idx].second);
			idx++;
		}
		ans = max(ans, b - arr[idx].second);
		if (arr[idx].first == cur) {
			idx++;
		}
	}
	cout << ans;
	return 0;
}