#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

int main() {
	fastio;
	int N, arr[60][4], ans = 0;
	set<pair<int, int>> s1;
	map<pair<int, int>, int> dict;
	
	cin >> N;
	// 라인 받기
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
		s1.insert({ arr[i][0], arr[i][1] });
		s1.insert({ arr[i][2], arr[i][3] });
	}
	
	//각 점들을 맵화
	int idx = 0;
	for (const auto& x : s1) {
		dict[x] = idx++;
	}
	
	int NN = s1.size();
	vector<vector<int>> adjm(NN, vector<int>(NN, 0));  // Pre-initialize with zeros
	
	// Build adjacency matrix
	rep(i, 0, N) {
		int a = dict[{ arr[i][0], arr[i][1] }];
		int b = dict[{ arr[i][2], arr[i][3] }];
		adjm[a][b]++;
		adjm[b][a]++;
	}
	
	vector<bool> v(NN, false);  // Use vector<bool> which is more memory efficient
	
	rep(i, 0, NN) {
		if (v[i])
			continue;
			
		bool Flag = true;
		queue<int> q;
		v[i] = true;
		q.push(i);
		
		while (!q.empty()) {
			int cur = q.front(); 
			q.pop();
			int cnt = 0;
			
			rep(nxt, 0, NN) {
				if (adjm[cur][nxt] == 0)
					continue;
				if (adjm[cur][nxt] > 1) {
					Flag = false;
				}
				
				cnt++;
				
				if (v[nxt])
					continue;
				v[nxt] = true;
				q.push(nxt);
			}
			
			if (cnt != 2)
				Flag = false;
		}
		
		if (Flag)
			ans++;
	}
	
	cout << ans << '\n';  // '\n' is faster than endl
	return 0;
}