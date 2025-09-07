#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, K, arr[100][2];

bool chck(LL width) {
	rep(i, 0, N - 1) {
		rep(j, i + 1, N) {
			int minX = min(arr[i][0], arr[j][0]) - 1;
			int minY = min(arr[i][1], arr[j][1]) - 1;

			LL maxX = minX + width;
			LL maxY = minY + width;
			int cnt = 0;
			rep(i, 0, N) {
				if (minX< arr[i][0] && maxX > arr[i][0] && minY< arr[i][1] && maxY > arr[i][1]) {
					cnt++;
					if (cnt >= K) {
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1];
	}
	if (K == 1) {
		cout << 4;
		return 0;
	}
	LL start = 2, end = 2e9 + 2;
	while (start <= end) {
		LL mid = (start + end) / 2;
		if (chck(mid)) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	cout << start * start;
	return 0;
}