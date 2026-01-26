#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

int N;
UI arr[40000];

int bs(UI * begin, int size, UI val) {
	int start = 0, end = size - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (begin[mid] < val) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return start;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	memset(arr, -1, sizeof(arr));
	cin >> N;
	cin >> arr[0];
	int cnter = 1;
	rep(i, 0, N - 1) {
		UI cur;
		cin >> cur;
		int idx = bs(arr, cnter, cur);
		arr[idx] = min(arr[idx], cur);
		if (idx + 1 > cnter) {
			cnter = idx + 1;
		}
	}
	cout << cnter;
	return 0;
}