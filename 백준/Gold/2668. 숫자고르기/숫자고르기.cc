#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, arr[100], startVal;
vector<int> ans;
int v[100];

void dfs(int num, int aidx) {
	v[num] = aidx;
	if (v[arr[num]] && v[arr[num]] != aidx) {
		return;
	}
	if (v[arr[num]] == aidx) {
		startVal = arr[num];
	}
	else {
		dfs(arr[num], aidx);
	}
	if (startVal != -1) {
		ans.push_back(num + 1);
	}
	if (num == startVal) {
		startVal = -1;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
		arr[i]--;
	}
	int area = 0;
	rep(i, 0, N) {
		if (v[i]) { continue; }
		dfs(i, ++area);
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int& item : ans) {
		cout << item << '\n';
	}
	return 0;
}