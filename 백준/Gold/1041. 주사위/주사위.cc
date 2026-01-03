#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>
#include <string>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))
using LL = unsigned long long;

using namespace std;

LL N, arr[6];
vector<vector<LL>> adjv;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N;
	rep(i, 0, 6) {
		cin >> arr[i];
	}

	adjv.resize(6);

	adjv[0].push_back(1);
	adjv[0].push_back(2);
	adjv[0].push_back(4);
	adjv[0].push_back(3);

	adjv[1].push_back(0);
	adjv[1].push_back(3);
	adjv[1].push_back(5);
	adjv[1].push_back(2);

	adjv[2].push_back(4);
	adjv[2].push_back(0);
	adjv[2].push_back(1);
	adjv[2].push_back(5);

	adjv[3].push_back(4);
	adjv[3].push_back(0);
	adjv[3].push_back(1);
	adjv[3].push_back(5);

	adjv[4].push_back(2);
	adjv[4].push_back(0);
	adjv[4].push_back(3);
	adjv[4].push_back(5);

	adjv[5].push_back(1);
	adjv[5].push_back(2);
	adjv[5].push_back(4);
	adjv[5].push_back(3);

	LL sum3 = 1e9, sum2 = 1e9, sum1 = 1e9;

	//3
	rep(i, 0, 6) {
		rep(j, 0, 4) {
			sum3 = min(sum3, arr[i] + arr[adjv[i][j]] + arr[adjv[i][(j + 1) % 4]]);
		}
	}

	//2
	rep(i, 0, 6) {
		for (const auto& adjn : adjv[i]) {
			sum2 = min(sum2, arr[i] + arr[adjn]);
		}
	}

	//1
	rep(i, 0, 6) {
		sum1 = min(sum1, arr[i]);
	}

	LL ans = 0;
	if (N == 1) {
		LL maxVal = 0;
		rep(i, 0, 6) {
			maxVal = max(maxVal, arr[i]);
			ans += arr[i];
		}
		ans -= maxVal;
	}
	else if (N == 2) {
		ans += 4 * sum3;
		ans += 4 * sum2;
	}
	else {
		ans += 4 * sum3;
		ans += (2 * N - 3) * 4 * sum2;
		ans += 4*(N - 1) * (N - 2) * sum1 + (N - 2) * (N - 2) * sum1;
	}
	cout << ans;
	return 0;
}