#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

struct Item {
	int p, d;
	bool operator< (const Item& b) const {
		if (d != b.d) {
			return d < b.d;
		}
		return p > b.p;
	}
};
int N;
vector<Item> arr;


int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	rep(i, 0, N) {
		cin >> arr[i].p >> arr[i].d;
	}
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<>> pq;
	rep(i, 0, N) {
		pq.push(arr[i].p);
		if (arr[i].d < pq.size()) {
			pq.pop();
		}
	}
	int ans=0;
	while (pq.size()) {
		ans += pq.top(); pq.pop();
	}
	cout << ans;

	return 0;
}