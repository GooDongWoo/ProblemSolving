#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	LL X1, Y1, R1, X2, Y2, R2;
	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;
	
	LL d_squared = (X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1);
	LL sum_squared = (R1 + R2) * (R1 + R2);
	
	if (d_squared < sum_squared) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}