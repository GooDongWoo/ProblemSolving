#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	rep(t, 1, T+1) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int maxSide = max({a, b, c});
		int sum = a + b + c - maxSide;
		
		cout << "Case #" << t << ": ";
		
		if (maxSide >= sum) {
			cout << "invalid!" << '\n';
		} else {
			if (a == b && b == c) {
				cout << "equilateral" << endl;
			} else if (a == b || b == c || a == c) {
				cout << "isosceles" << '\n';
			} else {
				cout << "scalene" << '\n';
			}
		}
	}
	return 0;
}