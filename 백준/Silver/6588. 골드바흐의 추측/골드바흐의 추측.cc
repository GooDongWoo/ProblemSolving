#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int n, m, sieve[1000001];
vector <int> plist;
void msieve() {
	sieve[0] = sieve[1] = 0;
	rep(i, 2, 1000001) {
		if (sieve[i]) {
			plist.push_back(i);
			for (LL j = (LL)i * i; j < 1000001; j += i) sieve[j] = 0;
		}
	}
}
int main() {
	fastio;
	fill(sieve, sieve + 1000001, 1);
	msieve();
	while (true) {
		cin >> n;
		if (n == 0)break;
		for (const auto& item : plist) {
			if (sieve[n - item] == 1) {
				printf("%d = %d + %d\n", n, item, n - item);
				break;
			}
		}
	}
	
	
    return 0;
}