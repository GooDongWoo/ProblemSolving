#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

int N, D, p, arr[101];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> D >> p;
	rep(i, 0, N)
		cin >> arr[i];
	int cnt = 0;
	rep(i, 0, N) {
		while (arr[i] > 0) {
			arr[i] -= D;
			if (arr[i] < 0) {
				arr[i + 1] -= (-arr[i]) * p / 100;
				i++;
			}
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}