#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Item {
	LL a, b;
};
int N, M, K;
Item arr[200000];

bool cmp1(const Item& a, const Item& b) {
	return a.a > b.a;
}
bool cmp2(const Item& a, const Item& b) {
	return a.b > b.b;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	rep(i, 0, N) {
		cin >> arr[i].a >> arr[i].b;
	}
	sort(arr, arr + N, cmp2);
	sort(arr + K, arr + N, cmp1);
	LL ans=0;
	rep(i, 0, M + K) {
		ans += arr[i].a;
	}
	cout << ans;
	return 0;
}