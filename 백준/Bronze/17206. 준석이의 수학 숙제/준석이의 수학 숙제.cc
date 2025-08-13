#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

#define MAX 80001
int T, N, arr[MAX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 3, MAX) {
		if (i % 3 == 0 || i % 7 == 0) {
			arr[i] += i;
		}
		arr[i] += arr[i - 1];
	}
	cin >> T;
	rep(i, 0, T) {
		int a;
		cin >> a;
		cout << arr[a] << '\n';
	}
	return 0;
}