#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MAX = 10000;
int T, v[5000];
bool isNotPrime[MAX];
vector<int> primes;
map<int, int> prime2idx;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	primes.reserve(5000);
	int idx = 0;
	rep(i, 2, MAX) {
		if (!isNotPrime[i]) {
			if (i > 999 && i < 10000) {
				primes.push_back(i);
				prime2idx[i] = idx++;
			}
			for (int p = i * i; p < MAX; p += i) {
				isNotPrime[p] = true;
			}
		}
	}
	int N = primes.size();
	vector<vector<int>> adjv;
	adjv.resize(N);
	rep(i, 0, N) {
		rep(j, i + 1, N) {
			int ret = 0;
			ret += ((primes[i] / 1000) == (primes[j] / 1000)) ? 1 : 0;
			ret += (((primes[i] % 1000) / 100) == ((primes[j] % 1000) / 100)) ? 1 : 0;
			ret += (((primes[i] % 100) / 10) == ((primes[j] % 100) / 10)) ? 1 : 0;
			ret += (((primes[i] % 10) / 1) == ((primes[j] % 10) / 1)) ? 1 : 0;
			if (ret == 3) {
				adjv[i].push_back(j);
				adjv[j].push_back(i);
			}
		}
	}
	cin >> T;
	rep(test_case, 0, T) {
		memset(v, 0, sizeof(v));
		int a, b;
		cin >> a >> b;
		int m1 = prime2idx[a];
		int m2 = prime2idx[b];
		queue<int> q;
		v[m1] = 1;
		q.push(m1);
		while (q.size()) {
			int cur = q.front(); q.pop();
			if (cur == m2) {
				break;
			}
			for (const int nxt : adjv[cur]) {
				if (v[nxt]) {
					continue;
				}
				v[nxt] = v[cur] + 1;
				q.push(nxt);
			}
		}
		if (v[m2]) {
			cout << v[m2] - 1 << '\n';
		}
		else {
			cout << "Impossible\n";
		}
	}
	return 0;
}