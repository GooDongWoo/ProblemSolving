#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>


#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int D;
string st, tmp, ans;
vector<string> dict[82];
queue<string> q;
unordered_set<string> v;

bool chck(string& gt, string cd) {
	int s1 = 0, s2 = 0;
	bool cnt = false;
	while (s1 < gt.size()) {
		if (gt[s1] != cd[s2]) {
			if (!cnt) {
				cnt = true;
				s2++;
			}
			else {
				return false;
			}
		}
		else {
			s1++;
			s2++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> D;
	cin >> st;
	ans = st;
	rep(i, 0, D) {
		cin >> tmp;
		dict[tmp.size()].push_back(tmp);
	}
	v.insert(st);
	q.push(st);
	while (q.size()) {
		string cur = q.front(); q.pop();
		for (const auto& cds : dict[cur.size() + 1]) {
			if (chck(cur, cds)) {
				if (ans.size() < cds.size()) {
					ans = cds;
				}
				v.insert(cds);
				q.push(cds);
			}
		}
	}
	cout << ans;
	return 0;
}