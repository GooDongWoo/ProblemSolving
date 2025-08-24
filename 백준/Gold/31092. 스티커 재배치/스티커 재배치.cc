#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

#define MAX 1e9
struct Item {
	char s;
	int d, a;
};
int N, M, K, origin[500], detach[500], buy[26], available[26], need[26], ccost, ans = MAX;
Item items[500];
string target;
vector<pair<int, int>> detach_attach[26];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	rep(i, 0, 26) {
		buy[i] = MAX;
	}
	rep(i, 0, M) {
		cin >> items[i].s >> items[i].d >> items[i].a;
		buy[items[i].s - 'a'] = min(buy[items[i].s - 'a'], items[i].a);
	}
	rep(i, 0, N) {
		cin >> origin[i];
		origin[i]--;
		detach[i] = items[origin[i]].d;
		if (detach[i] < buy[items[origin[i]].s - 'a']) {
			detach_attach[items[origin[i]].s - 'a'].push_back({ detach[i],i });
		}
	}
	rep(i, 0, 26) {
		sort(detach_attach[i].begin(), detach_attach[i].end());
	}
	cin >> target;
	rep(i, 0, N - K + 1) {
		ccost = 0;
		memset(available, 0, sizeof(available));
		memset(need, 0, sizeof(need));
		rep(j, 0, K) {
			if (items[origin[i + j]].s != target[j]) {
				ccost += detach[i + j];
				available[items[origin[i + j]].s - 'a']++;
				need[target[j] - 'a']++;
			}
		}
		// 현재 사용하고 있는 범위 [i, i + K)
		rep(j, 0, 26) {
			need[j] -= available[j];
			if (need[j] <= 0) {
				continue;
			}
			int idx = 0;
			while (idx < detach_attach[j].size() && need[j]>0) {
				int tidx = detach_attach[j][idx].second;
				int tcost = detach_attach[j][idx].first;
				if (!(i <= tidx && tidx < i + K)) {
					need[j]--;
					ccost += tcost;
				}
				idx++;
			}
			//이제 사고
			if (buy[j] < MAX) {
				ccost += buy[j] * need[j];
			}
			// 안되면 ccost=1e9하고 break;
			else {
				ccost = 1e9;
				break;
			}
		}
		ans = (ccost < ans) ? ccost : ans;
	}
	ans = (ans < MAX) ? ans : -1;
	cout << ans;
	return 0;
}