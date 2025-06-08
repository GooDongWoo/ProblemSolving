#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int N, Q;
unordered_map<int, LL> dict;

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		int tmp;
		cin >> tmp;
		dict[tmp]++;
	}
	cin >> Q;
	rep(i, 0, Q) {
		int a;
		unordered_map<int, LL> mini;
		cin >> a;
		rep(j, 0, a) {
			int tmp;
			cin >> tmp;
			mini[tmp]++;
		}
		bool Flag = 1;
		for (const auto& x : mini) {
			if (dict[x.first] - mini[x.first] < 0) {
				Flag = 0;
			}
		}
		if (Flag) {
			for (const auto& x : mini) {
				dict[x.first] -= mini[x.first];
			}
		}
		cin >> a;
		rep(j, 0, a) {
			int tmp;
			cin >> tmp;
			if (Flag) {
				dict[tmp]++;
			}
		}
	}
	vector<int> anslist;
	for (const auto& x : dict) {
		if (x.second != 0) {
			rep(i,0,x.second){
				anslist.push_back(x.first);
			}
		}
	}
	sort(anslist.begin(), anslist.end());
	printf("%lld\n",anslist.size());
	rep(i, 0, anslist.size()) {
		printf("%d ", anslist[i]);
	}
	return 0;
}