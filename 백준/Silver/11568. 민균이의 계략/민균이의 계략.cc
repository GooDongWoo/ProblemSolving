#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

#define fastio ios_base ::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)


int N, arr[1000], dp[1000], K;

int myLowerbound(int target, int arrsize) {
	int start, end, mid;
	start = 0;
	end = arrsize - 1;
	while (start <= end) {
		mid = (start + end) / 2;
		if (target > dp[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return start;
}

int main() {
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i];

	dp[0] = arr[0];
	K = 1;
	rep(i, 1, N) {
		int idx = myLowerbound(arr[i], K);
		dp[idx] = arr[i];
		if (idx == K)
			K++;
	}
	printf("%d\n", K);
	return 0;
}