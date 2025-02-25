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
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int N;

int main() {
	fastio;
	cin >> N;
	vector<vector<string>> arr(N);
	rep(i, 0, N) {
		int a;
		cin >> a;
		rep(j, 0, a) {
			string tmp;
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	}
	sort(arr.begin(), arr.end());
	int lev = 0;
	rep(i, 0, arr[0].size()) {
		rep(iter, 0, lev) printf("--");
		printf("%s\n",arr[0][i].c_str());
		lev++;
	}
	rep(i, 1, N) {
		int a, b,tidx;
		a = arr[i - 1].size();
		b = arr[i].size();
		tidx = 0;
		rep(j, 0, min(a, b)) {
			if (arr[i - 1][j] != arr[i][j]) {
				tidx = j;
				break;
			}	
		}
		rep(j, tidx, b) {
			rep(iter, 0, j) printf("--");
			printf("%s\n", arr[i][j].c_str());
		}
	}
}