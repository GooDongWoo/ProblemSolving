#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int N, M, v[1000];
vector<pair<int, int>> adjv[1000];

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M;
	rep(i, 0, N-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adjv[a].push_back({ c,b });
		adjv[b].push_back({ c,a });
	}
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		bool isFind = false;
		memset(v, 0, sizeof(v));
		queue<int> q;
		q.push(a);
		v[a] = 1;
		while (q.size() && !isFind) {
			int cur = q.front(); q.pop();
			for (const auto& nxtp : adjv[cur]) {
				int nxt = nxtp.second, nw = nxtp.first;
				if (v[nxt])continue;
				v[nxt] = v[cur] + nw;
				q.push(nxt);
				if (nxt == b) {
					isFind = true;
					break;
				}
			}
		}
		cout << v[b] - 1 << '\n';
	}


	return 0;
}