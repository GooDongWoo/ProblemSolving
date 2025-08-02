#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int K, cnter;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> K;
	while (K != 1) {
		rep(i, 2, K + 1) {
			if (K % i == 0) {
				K /= i;
				cnter++;
				break;
			}
		}
	}
	int bef = 1, exp = 0;
	while (bef < cnter) {
		bef *= 2;
		exp++;
	}
	cout << exp;
	return 0;
}