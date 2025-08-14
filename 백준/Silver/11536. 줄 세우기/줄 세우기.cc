#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N;
vector<string> origin,arr;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	origin.reserve(N);
	arr.reserve(N);
	rep(i, 0, N) {
		string a;
		cin >> a;
		origin.push_back(a);
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	if (arr == origin) {
		cout << "INCREASING";
		return 0;
	}
	sort(arr.begin(), arr.end(),greater<>());
	if (arr == origin) {
		cout << "DECREASING";
		return 0;
	}
	else {
		cout << "NEITHER";
		return 0;
	}
	return 0;
}