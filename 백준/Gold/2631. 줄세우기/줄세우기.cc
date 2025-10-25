#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N;
vector<int> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	int a;
	cin >> a;
	arr.push_back(a);
	rep(i, 1, N) {
		cin >> a;
		int idx = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
		if (idx >= arr.size()) {
			arr.push_back(a);
		}
		else {
			arr[idx] = a;
		}
	}
	cout << N - arr.size();
	return 0;
}