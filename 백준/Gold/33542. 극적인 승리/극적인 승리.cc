#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int A, B, N;
pair<int, int> p1[500001];
pair<int, int> p2[500001];

int lower_bound(int target) {
	int start, end, mid;
	start = 0;
	end = N;
	while (start <= end) {
		mid = (start + end) / 2;
		if (p2[mid].first < target)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return start;
}
int main() {
	fastio;
	cin >> A >> B >> N;
	rep(i, 0, N) {
		cin >> p1[i].first >> p2[i].first;
		p1[i].second = i + 1;
		p2[i].second = i + 1;
	}
	p1[N].first = 0; p1[N].second = -1;
	p2[N].first = 0; p2[N].second = -1;
	sort(p1, p1 + N + 1); sort(p2, p2 + N + 1);
	int target = A - B + 1;
	if (A < B) {
		printf("-1 -1\n");
		return 0;
	}
	vector<vector<int>> clist;
	rep(i, 0, N + 1) {
		int Li = p1[i].first;
		int Lidx = p1[i].second;
		int Rtarget = target - Li;
		int idx = lower_bound(Rtarget);
		//idx == N + 1;
		//p2[idx].second == Lidx
		if (idx == N + 1)
			continue;
		if (p2[idx].second == Lidx) {
			if (idx == N) {
				continue;
			}
			idx++;
		}
		int tmp = p1[i].first + p2[idx].first;
		clist.push_back({ tmp, Lidx, p2[idx].second });
	}
	sort(clist.begin(), clist.end());
	if (clist.size())
		printf("%d %d\n",clist[0][1], clist[0][2]);
	else
		printf("No\n");
	return 0;
}