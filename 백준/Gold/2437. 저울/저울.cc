#include <iostream>
#include <algorithm>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, arr[1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int sum = 0;
	for (int x : arr) {
		if (x > sum + 1) break;
		sum += x;
	}
	cout << sum + 1;
	return 0;
}