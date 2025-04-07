#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

int N, M, K, cnter;
vector<vector<int>> adjv;
bool chck[2000], destroyed[2000], v[2000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	adjv.resize(N);
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	cin >> K;
	rep(i, 0, K) {
		int a;
		cin >> a;
		a--;
		destroyed[a] = 1;
	}
	rep(i, 0, N) {
		if (destroyed[i] == 1) {
			bool Flag = 1;
			for (const int& nxt : adjv[i]) {
				if (destroyed[nxt] != 1) {
					Flag = 0;
				}
			}
			if (Flag == 1) {
				chck[i] = 1;
			}
		}
	}
	rep(i, 0, N) {
		if (chck[i]) {
			if (!v[i]) {
				v[i] = 1;
				cnter++;
			}
			for (const int& nxt : adjv[i]) {
				if (!v[nxt]) {
					v[nxt] = 1;
					cnter++;
				}
			}
		}
	}
	if (cnter == K) {
		vector<int> anslist;
		rep(i, 0, N) {
			if (chck[i])
				anslist.push_back(i + 1);
		}
		printf("%d\n", anslist.size());
		for (const int& x : anslist)
			printf("%d ", x);
	}
	else {
		printf("%d\n", -1);
	}
	return 0;
}