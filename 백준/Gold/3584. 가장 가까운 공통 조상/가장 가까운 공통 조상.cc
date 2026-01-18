#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

int T, N, table[10000][15], ridx, state[10000];
bool isNotRoot[10000];
vector<vector<int>> adjv, radjv;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> T;
	rep(test_case, 0, T) {
		cin >> N;
		memset(table, 0, sizeof(table));
		memset(isNotRoot, 0, sizeof(isNotRoot));
		adjv.clear(); adjv.resize(N);
		radjv.clear(); radjv.resize(N);
		rep(i, 0, N - 1) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			adjv[a].push_back(b);
			radjv[b].push_back(a);
			table[b][0] = a;
			isNotRoot[b] = 1;
		}
		rep(i, 0, N) {
			if (!isNotRoot[i]) {
				ridx = i;
				table[ridx][0] = ridx;
				break;
			}
		}
		// root에서 한번 bfs 돌려서 state 채우고
		queue<int> q;
		q.push(ridx);
		state[ridx] = 1;
		while (q.size()) {
			int cur = q.front(); q.pop();
			for (const int& child : adjv[cur]) {
				q.push(child);
				state[child] = state[cur] + 1;
			}
		}
		// 14번 정도 축지법 돌리고
		rep(j, 1, 15) {
			rep(i, 0, N) {
				table[i][j] = table[table[i][j - 1]][j - 1];
			}
		}
		// A,B 구하고
		int A, B;
		cin >> A >> B;
		A--; B--;
		// A랑 B의 위상이 같도록 큰 노드를 올려주고
		if (state[A] != state[B]) {
			if (state[A] > state[B]) {
				swap(A, B);
			}
			// B를 올려준다.
			// O(logN)으로 올리고 싶지만 귀찮으니 O(N)으로 올린다.
			while (state[A] != state[B]) {
				B = table[B][0];
			}
		}

		while (A != B) {// 이걸 반복함.
			int idx;
			rep(i, 0, 15) {
				if (table[A][i] == table[B][i]) {// table을 뒤져서 서로 같은 것이 언제 나오는지(tidx) 체크함;
					idx = i;
					break;
				}
			}
			// tidx - 1로 점프함.
			int tidx = max(0, idx - 1);
			A = table[A][tidx];
			B = table[B][tidx];
		}
		cout << A + 1 << '\n';
	}
	return 0;
}