#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int A1, P1, R1, P2;
	cin >> A1 >> P1;
	cin >> R1 >> P2;
	
	double slice_ratio = (double)A1 / P1;
	double whole_ratio = (M_PI * R1 * R1) / P2;
	
	if (whole_ratio > slice_ratio) {
		cout << "Whole pizza" << endl;
	} else {
		cout << "Slice of pizza" << endl;
	}
	
	return 0;
}