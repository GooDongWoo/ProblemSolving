#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int T, N, K;

int GCD(int a, int b) {
	if (a * b == 0) return 0;
	if (a < b) swap(a, b);
	if (a % b == 0) return b;
	return GCD(b, a % b);
}

int main() {
	fastio;
	cin >> T;
	rep(test, 1, T + 1) {
		printf("Data Set %d:\n", test);
		cin >> N >> K;
		rep(i, 0, N) {
			int intP; string fr;
			cin >> intP >> fr;
			int idx = fr.find('/', 0);
			string mul, div;
			rep(j, 0, idx)mul += fr[j];
			rep(j, idx+1, fr.size())div += fr[j];
			int a, b;
			a = stoi(mul);b = stoi(div);
			intP *= K;
			a *= K;
			int gcd = GCD(a, b);
			if (gcd == 0) printf("%d\n", intP);
			else {
				a /= gcd;b /= gcd;
				if (a >= b) {
					intP += (a / b); a = a % b;
				}
				if (a == 0) printf("%d\n", intP);
				else {
					printf("%d %d/%d\n", intP, a, b);
				}
			}
		}
		printf("\n");
	}
	return 0;
}