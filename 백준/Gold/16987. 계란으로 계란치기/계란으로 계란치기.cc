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

int N, arr[8][2], ans;

void bt(int idx) {
	if (idx >= N) {
		int mini = 0;
		rep(i, 0, N) {
			if (arr[i][0] <= 0) {
				mini++;
			}
		}
		ans = max(mini, ans);
	}
	else {
		// 현재 계란이 박살
		if (arr[idx][0] <= 0) {
			bt(idx + 1);
		}
		else {
			bool isany = false;
			//현재 계란이 살아있음
			rep(i, 0, N) {
				// 부딫힐 계란이 같거나 박살
				if (i == idx || arr[i][0] <= 0) {
					continue;
				}
				//부딫힐 계란을 부딫힌다.
				isany = true;
				arr[i][0] -= arr[idx][1];
				arr[idx][0] -= arr[i][1];
				bt(idx + 1);
				arr[i][0] += arr[idx][1];
				arr[idx][0] += arr[i][1];
			}
			if (!isany) {
				bt(idx + 1);
			}
		}
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1];
	}
	bt(0);
	cout << ans;
	return 0;
}