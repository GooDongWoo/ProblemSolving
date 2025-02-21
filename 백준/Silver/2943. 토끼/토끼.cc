#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, boxes[100001], cups[320], ans;;


int main() {
	fastio;
	cin >> N >> M;
	int K = (int)pow(N, 0.5);
	int start, num;
	int left, right;
	rep(i, 0, M) {
		ans = 0;
		cin >> num >> start;start--;
		if (num >= K) {
			left = (K - (start % K)) % K;
			rep(j, 0, left) {
				ans += ++boxes[start+1+j];
			}
			if (start + num == N) {
				right = (start + num) % K;
				if (right) {
					ans += (++cups[K+1]);
				}
			}
			else {
				right = (start + num) % K;
				rep(j, 0, right) {
					ans += ++boxes[start + num - j];
				}
			}
			num -= (left + right);
			rep(j, 0, num / K) {
				ans += (++cups[(start + left) / K + j]);
			}
		}
		else {
			rep(j, 0, num) {
				ans += ++boxes[start+1+j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}