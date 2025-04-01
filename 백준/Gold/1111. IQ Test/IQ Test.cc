#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

set<pair<int, int>> s1[2];
set<int> res;
int N, arr[50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i];
	if (N == 1) {
		printf("A\n");
		return 0;
	}
	rep(i, -20000, 20000)
		s1[0].insert({ i,arr[1] - (arr[0] * i) });

	rep(i, 2, N) {
		for (const auto& x : s1[0]) {
			if (x.first * arr[i - 1] + x.second == arr[i])
				s1[1].insert({ x.first ,x.second });
		}
		s1[0].swap(s1[1]);
		s1[1].clear();
	}
	for (const auto& x : s1[0])
		res.insert(x.first * arr[N - 1] + x.second);
	if (res.size() == 1)
		printf("%d\n", *res.begin());
	else if (res.size() > 1)
		printf("A\n");
	else
		printf("B\n");
	return 0;
}