#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, K, arr[50], cnter, ans;
int state = (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a')) | (1 << ('i' - 'a')) | (1 << ('c' - 'a'));

void bt(int idx) {
	if (cnter >= K) {
		int minicnter = 0;
		rep(i, 0, N) {
			if (((~state) & arr[i]) == 0) {
				minicnter++;
			}
		}
		ans = max(ans, minicnter);
		return;
	}
	else {
		rep(cur, idx, 26) {
			if (state & (1 << cur)) {
				continue;
			}
			state ^= (1 << cur);
			cnter++;
			bt(cur + 1);
			cnter--;
			state ^= (1 << cur);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> K;
	K -= 5;
	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		arr[i] = state;
		rep(j, 4, tmp.size() - 4) {
			arr[i] |= (1<<(tmp[j] - 'a'));
		}
	}
	if (K < 0) {
		cout << 0;
		return 0;
	}
	bt(0);
	cout << ans;
	return 0;
}