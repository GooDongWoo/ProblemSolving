#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;

int N, D;
pair<int, int> arr[100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> D;
	int  a, b;
	rep(i, 0, N) {
		cin >> a >> b;
		arr[i] = { a,b };
	}
	sort(arr, arr + N);
	int start, end;
	start = 0;
	end = N - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid].first < arr[0].first + D)
			start = mid + 1;
		else
			end = mid - 1;
	}
	int left = 0, right = 0;
	right = end;
	LL tot = 0, ans = 0;
	rep(i, 0, right + 1)
		tot += arr[i].second;
	ans = tot;
	rep(left, 1, N) {
		tot -= arr[left - 1].second;
		while (right + 1 < N && arr[left].first + D > arr[right + 1].first) {
			tot += arr[++right].second;
		}
		ans = max(ans, tot);
	}
	printf("%lld", ans);
	return 0;
}