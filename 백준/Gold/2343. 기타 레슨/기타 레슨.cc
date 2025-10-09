#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, arr[100001], psum[100001];

bool chck(int target) {
	int cnter = 0;
	int befIdx = 0;
	while (befIdx < N) {
		befIdx = upper_bound(psum, psum + N + 1, psum[befIdx] + target) - psum - 1;
		cnter++;
	}
	return (cnter <= M) ? true : false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M;
	int minVal = 0;
	rep(i, 1, N + 1) {
		cin >> arr[i];
		psum[i] = arr[i] + psum[i - 1];
		minVal = max(minVal, arr[i]);
	}
	int start = minVal, end = 1e9;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (chck(mid)) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start;
	return 0;
}
