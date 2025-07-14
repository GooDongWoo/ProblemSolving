#define rep(i,a,b) for(int i=a;i<b;++i)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, ans;
vector<pair<int, int>> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,0 });
		arr.push_back({ b,1 });
	}
	sort(arr.begin(), arr.end());
	int idx = 1, cnter = 1, bef = arr[0].first;
	while (idx < 2*N) {
		if (arr[idx].second == 0) {
			cnter++;
		}
		else {
			cnter--;
			if (cnter == 0) {
				ans += arr[idx].first - bef;
				idx++;
				if (idx < 2*N) {
					bef = arr[idx].first;
					cnter++;
				}
			}
		}
		idx++;
	}
	cout << ans;
	return 0;
}