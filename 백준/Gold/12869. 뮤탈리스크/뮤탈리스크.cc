#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

int N, v[61][61][61], l1[3] = { 1,3,9 };
bool mv[3];
vector<int> arr(3, 0);
queue<vector<int>> q;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	q.push(arr);
	v[arr[0]][arr[1]][arr[2]] = 1;
	while (q.size()) {
		auto curp = q.front();//여기서 참조로 받아와도 맹글링되나? 일단은 복사로
		q.pop();
		int a = curp[0], b = curp[1], c = curp[2];
		int na, nb, nc;
		rep(i, 0, 3) {
			if (mv[i]) continue;
			mv[i] = 1;
			na = max(0, a - l1[i]);
			rep(j, 0, 3) {
				if (mv[j]) continue;
				mv[j] = 1;
				nb = max(0, b - l1[j]);
				rep(k, 0, 3) {
					if (mv[k]) continue;
					nc = max(0, c - l1[k]);
					vector<int> narr = { na,nb,nc };
					sort(narr.begin(), narr.end());
					if (v[narr[0]][narr[1]][narr[2]]) continue;
					q.push(narr);
					v[narr[0]][narr[1]][narr[2]] = v[a][b][c] + 1;
					if (na == 0 && nb == 0 && nc == 0) {
						cout << v[0][0][0] - 1;
						return 0;
					}
				}
				mv[j] = 0;
				if (nc == 0) break;
			}
			mv[i] = 0;
			if (na == 0) break;
		}
	}
	cout << -999;
	return 0;
}