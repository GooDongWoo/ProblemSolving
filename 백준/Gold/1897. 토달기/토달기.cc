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

bool canInsertOne(const string& cur, const string& target) {
	int cidx = 0, tidx = 0;
	bool inserted = false;

	while (cidx < cur.size() && tidx < target.size()) {
		if (cur[cidx] == target[tidx]) {
			cidx++;
			tidx++;
		}
		else {
			if (inserted) {
				return false;
			}
			inserted = true;
			tidx++;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> D >> st;
	ans = st;

	rep(i, 0, D) {
		cin >> tmp;
		dict[tmp.size()].push_back(tmp);
	}

	v.insert(st);
	q.push(st);

	while (q.size()) {
		string cur = q.front();
		q.pop();

		int nextLen = cur.size() + 1;

		for (const string& cds : dict[nextLen]) {
			if (v.count(cds)) continue;

			if (canInsertOne(cur, cds)) {
				if (cds.size() > ans.size()) {
					ans = cds;
				}

				v.insert(cds);
				q.push(cds);
			}
		}
	}

	cout << ans << endl;
	return 0;
}