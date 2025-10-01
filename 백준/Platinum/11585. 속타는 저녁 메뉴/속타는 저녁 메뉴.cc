#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, PI[1000000], numerator, denominator;
string target, origin;

void makePI() {
	int cnt = 0;
	rep(cur, 1, target.size()) {
		while (cnt > 0 && target[cur] != target[cnt]) {
			cnt = PI[cnt - 1];
		}
		if (target[cur] == target[cnt]) {
			cnt++;
		}
		PI[cur] = cnt;
	}
	return;
}

void KMP() {
	int cnt = 0;
	rep(cur, 0, 2 * N - 1) {
		while (cnt > 0 && origin[cur] != target[cnt]) {
			cnt = PI[cnt - 1];
		}
		if (origin[cur] == target[cnt]) {
			cnt++;
		}
		if (cnt == N) {
			numerator++;
			cnt = PI[cnt - 1];
		}
	}
	return;
}

int gcd(int a, int b) {
	if (a * b == 0) {
		return 0;
	}
	if (a < b) {
		swap(a, b);
	}
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N;
	char c;
	rep(i, 0, N) {
		cin >> c;
		target += c;
	}
	rep(i, 0, N) {
		cin >> c;
		origin += c;
	}
	origin = origin + origin;
	makePI();
	KMP();
	denominator = N;
	int gcdVal = gcd(numerator, denominator);
	cout << numerator / gcdVal << '/' << denominator / gcdVal;
	return 0;
}