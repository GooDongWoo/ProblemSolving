#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

struct Item {
	int due, score;
	bool operator<(const Item& b) {
		return tie(b.score, due) < tie(score, b.due);
	}
};
int N, ans;
Item arr[1000];
bool chck[1001];

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i].due >> arr[i].score;
	}
	sort(arr, arr + N);
	chck[0] = 1;
	rep(i, 0, N) {
		int minus = 0;
		while (arr[i].due - minus >= 0) {
			if (chck[arr[i].due - minus] == 1) {
				minus++;
			}
			else{
				chck[arr[i].due - minus] = 1;
				ans += arr[i].score;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}