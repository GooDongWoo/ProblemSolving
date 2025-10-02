#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

vector<int> getPi(const vector<int>& p) {
	int m = p.size();
	vector<int> pi(m, 0);
	int j = 0;
	rep(i, 1, m) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

void solve() {
	string item, word, ori;
	cin >> item >> word >> ori;
	int c2idx[256] = { 0 };
	rep(i, 0, item.size()) {
		c2idx[item[i]] = i;
	}

	vector<int> word_int(word.size());
	rep(i, 0, word.size()) {
		word_int[i] = c2idx[word[i]];
	}
	vector<int> pi = getPi(word_int);

	vector<int> sols;
	rep(shift, 0, item.size()) {
		int cnt = 0;
		int j = 0;
		rep(i, 0, ori.size()) {
			int cidx = c2idx[ori[i]];
			int didx = (cidx - shift + item.size()) % item.size();
			while (j > 0 && didx != word_int[j]) {
				j = pi[j - 1];
			}
			if (didx == word_int[j]) {
				if (j == word.size() - 1) {
					cnt++;
					j = pi[j];
				}
				else {
					j++;
				}
			}
		}
		if (cnt == 1) {
			sols.push_back(shift);
		}
	}
	if (sols.size() == 0) {
		cout << "no solution\n";
	}
	else if (sols.size() == 1) {
		cout << "unique: " << sols[0] << "\n";
	}
	else {
		cout << "ambiguous:";
		for (int sol : sols) {
			cout << " " << sol;
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	int test_cases;
	cin >> test_cases;
	while (test_cases--) {
		solve();
	}

	return 0;
}