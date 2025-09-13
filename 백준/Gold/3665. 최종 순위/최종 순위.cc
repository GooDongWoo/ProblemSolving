#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int T, N, M, arr[500], incnter[501], v[501];
vector<set<int>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N;
		adjv.clear();
		adjv.resize(N + 1);
		memset(incnter, 0, sizeof(incnter));
		memset(v, 0, sizeof(v));
		rep(i, 0, N) {
			cin >> arr[i];
		}
		rep(i, 0, N - 1) {
			rep(j, i + 1, N) {
				adjv[arr[i]].insert(arr[j]);
				incnter[arr[j]]++;
			}
		}
		cin >> M;
		rep(i, 0, M) {
			int a, b;
			cin >> a >> b;
			if (adjv[a].count(b) == 0) {
				swap(a, b);
			}
			adjv[a].erase(b);
			incnter[b]--;

			adjv[b].insert(a);
			incnter[a]++;
		}
		int ErrT = 0;
		queue<int> q;
		rep(i, 1, N + 1) {
			if (incnter[i] == 0) {
				q.push(i);
				v[i] = 1;
			}
		}
		if (q.size() == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		vector<int> anslist;
		while (q.size() && !ErrT) {
			if (q.size() > 1) {
				ErrT = 1;
				break;
			}
			int cur = q.front(); q.pop();
			anslist.push_back(cur);
			for (const auto& nxt : adjv[cur]) {
				if (v[nxt]) {
					ErrT = 2;
					break;
				}
				incnter[nxt]--;
				if (incnter[nxt] == 0) {
					q.push(nxt);
					v[nxt] = 1;
				}
			}
		}
		if (anslist.size() != N) {
			ErrT = 2;
		}
		if (ErrT == 1) {
			cout << "?\n";
			continue;
		}
		else if (ErrT == 2) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		else {
			for (const auto& x : anslist) {
				cout << x << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
