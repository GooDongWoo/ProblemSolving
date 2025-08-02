#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	double K, D1, D2;
	cin >> K;
	cin >> D1 >> D2;
	
	double height_squared = K * K - ((D1 - D2) / 2) * ((D1 - D2) / 2);
	
	cout << height_squared << endl;
	
	return 0;
}