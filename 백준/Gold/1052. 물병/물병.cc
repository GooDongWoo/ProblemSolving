#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int N, K, cnter, ans;
vector<char> arr;

void run(vector<char>& vec, int index) {
	if (index >= vec.size()) {
		vec.push_back('1');
		return;
	}
	if (vec[index] == '1') {
		vec[index] = '0';
		run(vec, index + 1);
	}
	else {
		vec[index] = '1';
		return;
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> K;
	while (N) {
		if (N & 1) {
			arr.push_back('1');
			cnter++;
		}
		else {
			arr.push_back('0');
		}
		N >>= 1;
	}
	while (cnter > K) {
		// 못찾을리가 없다 최소가 1이니
		int idx = 0;
		rep(i, 0, arr.size()) {
			if (arr[i] == '1') {
				idx = i;
				break;
			}
		}

		int val = (1 << idx);
		ans += val;
		run(arr, idx);

		cnter = 0;
		rep(i, 0, arr.size()) {
			if (arr[i] == '1') {
				cnter++;
			}
		}
	}
	cout << ans;
	return 0;
}