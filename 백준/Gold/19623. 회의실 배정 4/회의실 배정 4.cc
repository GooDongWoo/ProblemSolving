#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

struct Item {
	int s, e, num;
	bool operator<(const Item& o)const {
		return s < o.s;
	}
};
int N, a, b, c, dp[200000];
Item arr[100000];
set<int> s1;
vector<int> narr;

int lbs(int num) {
	int start, end, mid;
	start = 0;
	end = N - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid].s < num) start = mid + 1;
		else end = mid - 1;
	}
	return start;
}
int ubs(int num) {
	int start, end, mid;
	start = 0;
	end = N - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid].s <= num) start = mid + 1;
		else end = mid - 1;
	}
	return start;
}
int bs2(int num) {
	int start, end, mid;
	start = 0;
	end = narr.size() - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (narr[mid] < num) start = mid + 1;
		else end = mid - 1;
	}
	return start;
}
int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		cin >> a >> b >> c;
		arr[i] = { a,b,c };
		s1.insert(a); s1.insert(b);
	}
	sort(arr, arr + N);
	narr.reserve(2 * N);
	for (const auto& x : s1) narr.push_back(x);
	rep(i, 0, narr.size()) {
		//앞의 최댓값 끌고가기
		if (i > 0) dp[i] = max(dp[i - 1], dp[i]);
		// arr.s 중에서 narr[i]를 찾는다.
		int lidx = lbs(narr[i]);
		int ridx = ubs(narr[i]);
		// 없으면 패스
		rep(idx, lidx, ridx) {
			if (idx >= N) continue;
			if (arr[idx].s != narr[i])continue;
			// 있으면 거기서 dp조짐
			int idx1 = bs2(arr[idx].s);
			int idx2 = bs2(arr[idx].e);
			dp[idx2] = max(dp[idx2], dp[idx1] + arr[idx].num);
		}
	}
	printf("%d", dp[narr.size() - 1]);
}