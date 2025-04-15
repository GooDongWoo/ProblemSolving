#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int N, arr[60][4], ans;
set<pair<int, int>> s1;
map<pair<int, int>, int> dict;
vector<vector<int>> adjm;
bool v[120];

int main() {
	fastio;
	cin >> N;
	// 라인 받기
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
		s1.insert({ arr[i][0] ,arr[i][1] });
		s1.insert({ arr[i][2] ,arr[i][3] });
	}

	//각 점들을 맵화
	int idx = 0;
	for (const auto& x : s1) {
		dict[x] = idx++;
	}

	int NN = s1.size();
	adjm.resize(NN);
	rep(i, 0, NN)
		adjm[i].resize(NN);

	// a==b
	// N_i == N_(i+1)
	rep(i, 0, N) {
		int a = dict[{ arr[i][0], arr[i][1] }];
		int b = dict[{ arr[i][2], arr[i][3] }];
		adjm[a][b]++;
		adjm[b][a]++;
	}

	rep(i, 0, NN) {
		if (v[i])
			continue;
		bool Flag = 1;
		queue<int> q;

		v[i] = 1;
		q.push(i);
		while (q.size()) {
			int cur = q.front(); q.pop();
			int cnt = 0;

			rep(nxt, 0, NN) {
				if (adjm[cur][nxt] == 0)
					continue;

				if (adjm[cur][nxt] > 1)
					Flag = 0;
				
				cnt++;
				
				if (v[nxt])
					continue;
				v[nxt] = 1;
				q.push(nxt);
			}
			if (cnt != 2)
				Flag = 0;
		}
		if (Flag)
			ans++;
	}
	printf("%d\n", ans);
}