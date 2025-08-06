#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, K, arr1[10000], arr2[10000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	rep(i, 0, N) {
		cin >> arr1[i];
		arr2[i] = arr1[i];
	}
	sort(arr1, arr1 + N);
	int i = 0;
	while (K && i < N) {
		int cidx = 0, tidx = N - 1 - i;
		rep(j, 0, (tidx / 2)+1) {
			if (arr2[j] == arr1[tidx]) {
				cidx = j;
				break;
			}
			if (arr2[tidx - j] == arr1[tidx]) {
				cidx = tidx - j;
				break;
			}
		}
		if (cidx != tidx) { //swap
			swap(arr2[cidx], arr2[tidx]);
			K--;
		}
		i++;
	}
	if (K > 0) {
		cout << -1;
	}
	else {
		rep(i, 0, N) {
			cout << arr2[i] << ' ';
		}
	}
	return 0;
}