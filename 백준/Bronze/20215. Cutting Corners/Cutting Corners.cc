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
	int w, h;
	cin >> w >> h;
	
	double rectangle_cut = w + h;
	double diagonal_cut = sqrt(w * w + h * h);
	double difference = rectangle_cut - diagonal_cut;
	
	cout << fixed << setprecision(9) << difference << endl;
	
	return 0;
}