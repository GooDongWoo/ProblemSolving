#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string balancedTernary(long long n) {
	if (n == 0) return "0";

	string result = "";
	while (n) {
		long long remainder = ((n % 3) + 3) % 3;
		n = (n - remainder) / 3;

		if (remainder == 0) {
			result = "0" + result;
		}
		else if (remainder == 1) {
			result = "1" + result;
		}
		else {
			result = "T" + result;
			n++;
		}
	}
	return result;
}

int main() {
	fastio;
	long long N;
	cin >> N;
	cout << balancedTernary(N) << endl;
	return 0;
}