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
	int T;
	cin >> T;
	
	double result = (T * T) / 4.0;
	int answer = round(result);
	
	cout << answer << endl;
	
	return 0;
}