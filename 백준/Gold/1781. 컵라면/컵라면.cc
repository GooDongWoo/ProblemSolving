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

struct Item {
	int d, c;
	bool operator >(const Item& b) {
		if (c != b.c) {
			return c > b.c;
		}
		return d < b.d;
	}
};
int N, parent[200000], minval[200000], childs[200000];
LL ans;
bool v[200000];
vector<Item> arr;

int Find(int num) {
	if (parent[num] != num) {
		parent[num] = Find(parent[num]);
	}
	return parent[num];
}

void Union(int a, int b) {
	int pa, pb;
	pa = Find(a);
	pb = Find(b);
	if (pa == pb) {
		return;
	}
	if (childs[pa] < childs[pb]) {
		swap(pa, pb);
	}
	//child[pa]가 무조건 더 큼; -> pb를 pa에 달아버린다.
	parent[pb] = pa;
	childs[pa] += childs[pb];
	minval[pa] = min(minval[pa], minval[pb]);
	return;
}

void Init() {
	memset(v, 0, sizeof(v));
	rep(i, 0, N) {
		parent[i] = i;
		minval[i] = i;
		childs[i] = 1;
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;
	arr.resize(N);
	rep(i, 0, N) {
		cin >> arr[i].d >> arr[i].c;
		arr[i].d--;
	}
	sort(arr.begin(), arr.end(), greater<>());

	Init();
	rep(i, 0, N) {
		int deads = arr[i].d;
		int cups = arr[i].c;
		int target;
		if (!v[deads]) {
			target = deads;
			v[target] = 1;
			ans += cups;
		}
		else {
			int pd = Find(deads);

			if (minval[pd] == 0) {
				continue;
			}

			target = minval[pd] - 1;
			v[target] = 1;
			ans += cups;
		}
		//왼쪽과 union
		if (target > 0 && v[target - 1]) {
			Union(target, target - 1);
		}
		//오른쪽과 union
		if (target < N - 1 && v[target + 1]) {
			Union(target, target + 1);
		}
	}
	cout << ans;
	return 0;
}