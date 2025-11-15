#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

struct State {
	int l, r, s;
};
int T, N;
string word;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> T;
	rep(test_case, 0, T) {
		cin >> word;
		N = word.size();
		int ans = 2;
		stack<State> stck;
		stck.push({ 0,N - 1,0 });
		while (stck.size()) {
			auto curp = stck.top(); stck.pop();
			int lp = curp.l, rp = curp.r, cs = curp.s;
			if (!(lp < rp)) {
				if (cs) {
					ans = 1;
				}
				else {
					ans = 0;
				}
				break;
			}
			if (word[lp] == word[rp]) {
				stck.push({ lp + 1,rp - 1,cs });
			}
			else {
				if (cs != 0) {
					continue;
				}
				if (word[lp + 1] == word[rp]) {
					stck.push({ lp + 1,rp,cs + 1 });
				}
				if (word[lp] == word[rp - 1]) {
					stck.push({ lp,rp - 1,cs + 1 });
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}