#include <iostream>
#include <utility>
#include <stack>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, arr[1000001], ans[1000001];;
stack<pair<int, int>> stck;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
		ans[i] = -1;
	}
	rep(i, 1, N + 1) {
		while (stck.size() && arr[i] > stck.top().first) {
			ans[stck.top().second] = arr[i];
			stck.pop();
		}
		stck.push({ arr[i] ,i });
	}
	rep(i, 1, N + 1) {
		cout << ans[i] << ' ';
	}
	return 0;
}