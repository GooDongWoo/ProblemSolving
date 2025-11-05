#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MAX = 2000;
int N, v[MAX][MAX];
queue<pair<int, int>> q;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	q.push({ 1,0 });// val,clipboard
	v[1][0] = 1;
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cur = curp.first, clipboard = curp.second;
		if (cur == N) {
			cout << v[cur][clipboard] - 1;
			return 0;
		}
		int nxt;
		if (v[cur][cur] == 0) {
			v[cur][cur] = v[cur][clipboard] + 1;
			q.push({ cur,cur });
		}
		nxt = cur + clipboard;
		if (nxt < MAX && v[nxt][clipboard] == 0) {
			v[nxt][clipboard] = v[cur][clipboard] + 1;
			q.push({ nxt,clipboard });
		}
		nxt = cur - 1;
		if (0 <= nxt && nxt < MAX && v[nxt][clipboard] == 0) {
			v[nxt][clipboard] = v[cur][clipboard] + 1;
			q.push({ nxt,clipboard });
		}
	}
	return 0;
}