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

int N, S, arr[40];
LL ans;
map<int, LL> m1, m2;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N >> S;
	rep(i, 0, N) {
		cin >> arr[i];
	}

	rep(i, 0, N / 2) {
		vector<int> l1;
		l1.reserve(m1.size());
		for (auto& item : m1) {
			l1.push_back(item.first);
		}
		if (arr[i] >= 0) {
			for (int j = l1.size() - 1; j >= 0; j--) {
				m1[l1[j] + arr[i]] += m1[l1[j]];
			}
		}
		else {
			for (int j = 0; j < l1.size(); j++) {
				m1[l1[j] + arr[i]] += m1[l1[j]];
			}
		}
		m1[arr[i]]++;
	}
	rep(i, N / 2, N) {
		vector<int> l1;
		l1.reserve(m2.size());
		for (auto& item : m2) {
			l1.push_back(item.first);
		}
		if (arr[i] >= 0) {
			for (int j = l1.size() - 1; j >= 0; j--) {
				m2[l1[j] + arr[i]] += m2[l1[j]];
			}
		}
		else {
			for (int j = 0; j < l1.size(); j++) {
				m2[l1[j] + arr[i]] += m2[l1[j]];
			}
		}
		m2[arr[i]]++;
	}
	//m1
	ans += m1[S];
	//m2
	ans += m2[S];
	//m1+m2
	for (auto item : m1) {
		ans += item.second * m2[S - item.first];
	}
	cout << ans;
	return 0;
}