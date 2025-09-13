#include <iostream>
#include <algorithm>
#include <vector>
#include <string> // string 사용을 위해 추가
#include <set>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N;
vector<string> words;
vector<set<int>> adjv;
int incnter[26];
bool used_alpha[26];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	words.resize(N);
	adjv.resize(26);
	memset(incnter, 0, sizeof(incnter));
	memset(used_alpha, false, sizeof(used_alpha));

	rep(i, 0, N) {
		cin >> words[i];
		for (char c : words[i]) {
			used_alpha[c - 'a'] = true;
		}
	}

	bool impossible = false;
	rep(i, 0, N - 1) {
		string& s1 = words[i];
		string& s2 = words[i + 1];
		int len = min(s1.length(), s2.length());

		bool diff = false;
		rep(j, 0, len) {
			if (s1[j] != s2[j]) {
				int u = s1[j] - 'a';
				int v = s2[j] - 'a';
				if (adjv[u].count(v) == 0) {
					adjv[u].insert(v);
					incnter[v]++;
				}
				diff = true;
				break;
			}
		}
		if (!diff && s1.length() > s2.length()) {
			impossible = true;
			break;
		}
	}

	if (impossible) {
		cout << "!\n";
		return 0;
	}

	queue<int> q;
	int used_count = 0;
	rep(i, 0, 26) {
		if (used_alpha[i]) {
			used_count++;
			if (incnter[i] == 0) {
				q.push(i);
			}
		}
	}

	vector<int> anslist;
	bool ambiguous = false;

	while (!q.empty()) {
		if (q.size() > 1) {
			ambiguous = true;
		}

		int cur = q.front(); q.pop();
		anslist.push_back(cur);

		for (const auto& nxt : adjv[cur]) {
			incnter[nxt]--;
			if (incnter[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	if (anslist.size() != used_count) {
		cout << "!\n";
	}
	else if (ambiguous) {
		cout << "?\n";
	}
	else {
		for (const auto& x : anslist) {
			cout << (char)(x + 'a');
		}
		cout << "\n";
	}

	return 0;
}