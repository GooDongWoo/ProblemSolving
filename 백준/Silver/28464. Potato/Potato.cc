#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int N, arr[200000];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int min1 = 0, max1 = 0;
	rep(i, 0, (N / 2)) {
		min1 += arr[i];
	}
	rep(i, (N / 2), N) {
		max1 += arr[i];
	}
	cout << min1 << " " << max1;
	return 0;
}