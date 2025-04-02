#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

int N, K, T, arr[200000], cnter, idx;
LL ct;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K >> T;
	rep(i, 0, N)
		cin >> arr[i];

	sort(arr, arr + N);
	ct = T;
	stack<int> stck;

	rep(i, 0, K) {
		while (idx < N && arr[idx] < ct) {
			stck.push(arr[idx]);
			idx++;
		}
		if (stck.size() == 0)
			break;
		ct += stck.top();
		stck.pop();
	}
	printf("%lld", ct);

	return 0;
}