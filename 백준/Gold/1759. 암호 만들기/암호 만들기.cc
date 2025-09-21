#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int L, C, cnt[2];
set<char> moeum;
vector<char> tot;
string ans;

void bt(int depth, int cidx) {
	if (depth == L) {
		if (cnt[0] >= 1 && cnt[1] >= 2) {
			cout << ans << '\n';
		}
		return;
	}
	else {
		rep(i, cidx, tot.size()) {
			int isjaeum;
			if (moeum.count(tot[i])) {
				isjaeum = 0;
			}
			else {
				isjaeum = 1;
			}
			ans += tot[i];
			cnt[isjaeum]++;
			bt(depth + 1, i + 1);
			ans.pop_back();
			cnt[isjaeum]--;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> L >> C;
	for (const auto& x : { 'a','e','i','o','u' }) moeum.insert(x);
	rep(i, 0, C) {
		char c;
		cin >> c;
		tot.push_back(c);
	}
	sort(tot.begin(), tot.end());
	bt(0, 0);
	return 0;
}