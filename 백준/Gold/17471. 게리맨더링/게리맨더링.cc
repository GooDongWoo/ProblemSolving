#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, people[10], tot, ans = 1e9, minitot;
vector<vector<int>> adjv;
int bitmasking;

bool chck(int cnter) {
	int minicnter = 0;
	bool v[10];
	memset(v, 0, sizeof(v));
	queue<int> q;
	v[N - 1] = 1;
	q.push(N - 1);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int nxt : adjv[cur]) {
			if (v[nxt] || (bitmasking & (1 << nxt)) == 0) {
				continue;
			}
			v[nxt] = 1;
			q.push(nxt);
			minicnter++;
		}
	}

	if (minicnter == cnter) {
		int minileft = 0;
		int starter = 0;
		int tmp = bitmasking;
		while (tmp & 1) {
			tmp >>= 1;
			starter++;
		}
		memset(v, 0, sizeof(v));
		v[starter] = 1;
		q.push(starter);
		while (q.size()) {
			int cur = q.front(); q.pop();
			minileft++;
			for (int nxt : adjv[cur]) {
				if (v[nxt] || (bitmasking & (1 << nxt))) {
					continue;
				}
				v[nxt] = 1;
				q.push(nxt);
			}
		}
		if (minileft + 1 + minicnter == N) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void bt(int idx, const int poss, const int cnter) {
	if (idx == cnter) {
		if (chck(cnter)) {
			ans = min(ans, abs(minitot - (tot - minitot)));
		}
		return;
	}
	else {
		rep(i, poss, N) {
			bitmasking ^= (1 << i);
			minitot += people[i];
			bt(idx + 1, i + 1, cnter);
			bitmasking ^= (1 << i);
			minitot -= people[i];
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	adjv.resize(N);
	rep(i, 0, N) {
		cin >> people[i];
		tot += people[i];
	}
	rep(i, 0, N) {
		int num;
		cin >> num;
		rep(j, 0, num) {
			int e;
			cin >> e; e--;
			adjv[i].push_back(e);
			adjv[e].push_back(i);
		}
	}
	bitmasking = (1 << (N - 1));
	minitot = people[N - 1];
	rep(i, 0, N - 1) {// N은 포함이라고 가정
		bt(0, 0, i);
	}
	cout << ((ans == 1e9) ? -1 : ans);
}