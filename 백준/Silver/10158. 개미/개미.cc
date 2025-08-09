#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int W, H, P, Q, T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> W >> H >> P >> Q >> T;
	P += T;
	Q += T;
	P %= (2 * W);
	Q %= (2 * H);
	if (P >= W && Q >= H) {//1
		P = 2 * W - P;
		Q = 2 * H - Q;
	}
	else if (P <= W && Q >= H) {//2
		Q = 2 * H - Q;
	}
	else if (P <= W && Q <= H) {//3
		
	}
	else {//4
		P = 2 * W - P;
	}
	cout << P << ' ' << Q;
	return 0;
}