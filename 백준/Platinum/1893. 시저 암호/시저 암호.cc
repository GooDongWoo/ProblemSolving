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
	int char_to_idx[256] = { 0 };
	rep(i, 0, item.size()) {
		char_to_idx[(unsigned char)item[i]] = i;
	}

	vector<int> word_int(word.size());
	rep(i, 0, word.size()) {
		word_int[i] = char_to_idx[(unsigned char)word[i]];
	}
	vector<int> pi = getPi(word_int);

	vector<int> solutions;
	rep(shift, 0, item.size()) {
		int match_count = 0;
		int j = 0;
		rep(i, 0, ori.size()) {
			int current_char_idx = char_to_idx[(unsigned char)ori[i]];
			int decrypted_idx = (current_char_idx - shift + item.size()) % item.size();
			while (j > 0 && decrypted_idx != word_int[j]) {
				j = pi[j - 1];
			}
			if (decrypted_idx == word_int[j]) {
				if (j == word.size() - 1) {
					match_count++;
					j = pi[j];
				}
				else {
					j++;
				}
			}
		}
		if (match_count == 1) {
			solutions.push_back(shift);
		}
	}
	if (solutions.size() == 0) {
		cout << "no solution\n";
	}
	else if (solutions.size() == 1) {
		cout << "unique: " << solutions[0] << "\n";
	}
	else {
		cout << "ambiguous:";
		for (int sol : solutions) {
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