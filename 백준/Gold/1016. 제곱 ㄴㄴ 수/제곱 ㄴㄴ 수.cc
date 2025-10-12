#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

const int SQRTMAX = 1e6;
LL S, E;
bool isNoPrime[1000001];
vector<LL> sqps;

void makesqps() {
	memset(isNoPrime, 0, sizeof(isNoPrime));
	rep(cur, 2, 1000000) {
		if (!isNoPrime[cur]) {
			sqps.push_back(((LL)cur) * cur);
			for (LL j = ((LL)cur) * cur; j < 1000000; j += cur) {
				isNoPrime[j] = true;
			}
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> S >> E;
	makesqps();
	memset(isNoPrime, 0, sizeof(isNoPrime));
	for (const LL sqp : sqps) {
		if (sqp > E) {
			break;
		}
		LL sVal = (S % sqp != 0) ? (sqp * (S / sqp + 1)) : (sqp * (S / sqp));
		while (sVal <= E) {
			isNoPrime[sVal - S] = true;
			sVal += sqp;
		}
	}
	int cnter = 0;
	rep(i, 0, E-S+1) {
		if (!isNoPrime[i]) {
			cnter++;
		}
	}
	cout << cnter;
	return 0;
}