#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

string s, t;

int main() {
	fastio;
	cin >> s >> t;
	string rs(s);
	reverse(rs.begin(), rs.end());
	if ((s == t) || (t.find(s) == 0 && t.find('B', s.size()) == -1)) {
		printf("1"); return 0;
	}
	if (t[0] == 'A') {
		printf("0"); return 0;
	}
	if (t.find(s) != -1) {
		vector <int> idxList;
		int idx = t.find(s, 0);
		while (idx != -1) {
			idxList.push_back(idx);
			idx = t.find(s, idx+1);
		}
		int slen = s.size();
		for (const int x : idxList) {
			int lbcnter = 0, rbcnter = 0;
			rep(i, 0, x) {
				if (t[i] == 'B')
					lbcnter++;
			}
			rep(i, x+slen, t.size()) {
				if (t[i] == 'B')
					rbcnter++;
			}
			if (lbcnter == rbcnter) {
				printf("1"); return 0;
			}
		}
	}
	if (t.find(rs) != -1) {
		vector <int> idxList;
		int idx = t.find(rs, 0);
		while (idx != -1) {
			idxList.push_back(idx);
			idx = t.find(rs, idx+1);
		}
		int slen = s.size();
		for (const int x : idxList) {
			int lbcnter = 0, rbcnter = 0;
			rep(i, 0, x) {
				if (t[i] == 'B')
					lbcnter++;
			}
			rep(i, x + slen, t.size()) {
				if (t[i] == 'B')
					rbcnter++;
			}
			if (lbcnter == rbcnter+1) {
				printf("1"); return 0;
			}
		}
	}
	printf("0"); return 0;
}