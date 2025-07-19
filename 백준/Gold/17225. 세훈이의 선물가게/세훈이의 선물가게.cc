#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int consumes[2], N;
vector<pair<int, int>> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> consumes[0] >> consumes[1] >> N;
	int stime[2] = { 0 };
	int idx = 0;
	int presentNum = 1;
	rep(i, 0, N) {
		int arriveTime, num;
		char pType;
		cin >> arriveTime >> pType >> num;
		if (pType == 'B') {
			idx = 0;
		}
		else {
			idx = 1;
		}
		rep(miniCnt, 0, num) {
			stime[idx] = max(stime[idx], arriveTime);
			arr.push_back({ stime[idx],idx });
			stime[idx] += consumes[idx];
		}
	}
	sort(arr.begin(), arr.end());
	vector<int> anslist[2];
	rep(i, 0, arr.size()) {
		if (arr[i].second == 0) {
			anslist[0].push_back(i + 1);
		}
		else {
			anslist[1].push_back(i + 1);
		}
	}
	cout << anslist[0].size() << '\n';
	rep(i, 0, anslist[0].size()) {
		cout << anslist[0][i] << ' ';
	}

	cout << '\n';

	cout << anslist[1].size() << '\n';
	rep(i, 0, anslist[1].size()) {
		cout << anslist[1][i] << ' ';
	}

	return 0;
}