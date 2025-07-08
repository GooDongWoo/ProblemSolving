#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

vector<vector<int>>adjv;
int N;
bool v[100001], ans[100001];

int posto(int idx) {
	v[idx] = 1;
	bool found = 0;
	for (const auto& x : adjv[idx]) {
		if (v[x]) {
			continue;
		}
		if (posto(x) == 0) {
			found = 1;
		}
	}
	if (found == false) {
		return ans[idx] = 0;
	}
	else {
		return ans[idx] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	adjv.resize(N + 1);
	int a, b;
	rep(i, 0, N - 1) {
		cin >> a >> b;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	posto(1);
	rep(i, 1, N + 1) {
		if (ans[i]) {
			cout << "donggggas\n";
		}
		else {
			cout << "uppercut\n";
		}
	}
	return 0;
}