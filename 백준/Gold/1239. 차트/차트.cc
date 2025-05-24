#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, arr[8], ans, v[8], cds[8];

void bt(int idx) {
	if (idx == N) {
		set<int> s1;
		int minicnter = 0;
		int psum = cds[0];
		s1.insert(psum);
		rep(i, 1, N) {
			psum += cds[i];
			s1.insert(psum);
		}
		for (const int& x : s1) {
			if (x > 50) {
				break;
			}
			if (s1.find(50 + x) != s1.end()) {
				minicnter++;
			}
		}
		ans = max(ans, minicnter);
	}
	else {
		rep(i, 0, N) {
			if (v[i])
				continue;
			v[i] = 1;
			cds[idx] = arr[i];
			bt(idx + 1);
			v[i] = 0;
		}
	}
}

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i];
	bt(0);
	printf("%d\n", ans);
	return 0;
}