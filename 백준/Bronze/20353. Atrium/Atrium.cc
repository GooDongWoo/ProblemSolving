#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	LL a;
	cin >> a;
	
	double perimeter = 4 * sqrt(a);
	
	cout << fixed << setprecision(8) << perimeter << endl;
	
	return 0;
}
