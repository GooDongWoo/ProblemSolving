#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, K, pi[1000];
vector<vector<int>> mat;
bool IsExist;

void makepi(int start, vector<int>& arr) {
	int cnt = 0;
	rep(cur, start + 1, start + K) {
		while (cnt > 0 && arr[cur] != arr[start + cnt]) {
			cnt = pi[cnt - 1];
		}
		if (arr[cur] == arr[start + cnt]) {
			pi[cur - start] = ++cnt;
		}
	}
	return;
}

bool kmp(vector<int>& ori, vector<int>& cmp, int cmpStart) {
	int cnt = 0;
	rep(cur, 0, ori.size()) {
		while (cnt > 0 && ori[cur] != cmp[cmpStart + cnt]) {
			cnt = pi[cnt - 1];
		}
		if (ori[cur] == cmp[cmpStart + cnt]) {
			cnt++;
		}
		if (cnt >= K) {
			return true;
		}
	}
	return false;

}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> K;
	mat.resize(N);
	int TargetIdx = 0, TargetSize = 1e9;
	rep(i, 0, N) {
		int num;
		cin >> num;
		if (num < TargetSize) {
			TargetSize = num;
			TargetIdx = i;
		}
		mat[i].resize(num);
		rep(j, 0, num) {
			cin >> mat[i][j];
		}
	}
	rep(StartIdx, 0, TargetSize - K + 1) {
		memset(pi, 0, sizeof(pi));
		makepi(StartIdx, mat[TargetIdx]);
		IsExist = 1;
		rep(i, 0, N) {
			if (i == TargetIdx) {
				continue;
			}
			vector<int> reverseTmp(mat[i]); reverse(reverseTmp.begin(), reverseTmp.end());
			if (!kmp(mat[i], mat[TargetIdx], StartIdx) && !kmp(reverseTmp, mat[TargetIdx], StartIdx)) {
				IsExist = 0;
				break;
			}
		}
		if (IsExist) {
			break;
		}
	}
	cout << (IsExist ? "YES" : "NO");
	return 0;
}