#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int K, V, E, v[20000];
bool Flag;
vector<vector<int>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> K;
	rep(i, 0, K) {
		memset(v, 0, sizeof(v));
		adjv.clear();
		Flag = true;
		cin >> V >> E;
		adjv.resize(V);
		rep(i, 0, E) {
			int s, e;
			cin >> s >> e;
			s--; e--;
			adjv[s].push_back(e);
			adjv[e].push_back(s);
		}
		for (int i = 0; i < V && Flag; ++i) {
			if (v[i]) {
				continue;
			}
			queue<int> q;
			q.push(i);
			v[i] = 1;
			while (q.size() && Flag) {
				int cur = q.front(); q.pop();
				for (const int& nxt : adjv[cur]) {
					if (v[nxt] > 0) {
						if (v[nxt] != v[cur]) {
							continue;
						}
						else {
							Flag = 0;
							break;
						}
					}
					v[nxt] = (v[cur] == 1) ? 2 : 1;
					q.push(nxt);
				}
			}
		}
		if (Flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}