#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 4000001
int N, M, K, arr[MAX], p[MAX], Rank[MAX], Max1[MAX], v[MAX];

void init(int n) {
	rep(i, 0, n) {
		p[i] = i;
		Max1[i] = i;
		Rank[i] = 1;
	}
}
int find_(int num) {
	if (p[num] != num) p[num] = find_(p[num]);
	return p[num];
}

void union_(int a, int b) {
	int ap, bp;
	ap = find_(a);bp = find_(b);
	if (ap == bp) return;
	if (Rank[ap] < Rank[bp])swap(ap, bp);
	Rank[ap] += Rank[bp];
	p[bp] = ap;
	Max1[ap] = max(Max1[ap], Max1[bp]);
}
int ubs(int t) {
	int start = 0;
	int end = M - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (t < arr[mid]) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}
int main() {
	fastio;
	cin >> N >> M >> K;
	init(M);
	rep(i, 0, M) cin >> arr[i];
	sort(arr, arr + M);
	rep(_, 0, K) {
		int q;
		cin >> q;
		//find idx of q in arr
		int idx = ubs(q);
		//chck v[idx] equal to 1
		if (v[idx]) {// then find(idx).max and + 1
			int nidx = Max1[find_(idx)] + 1;
			v[nidx] =1;
			union_(nidx - 1, nidx);
			// aft chck; and union
			if (nidx + 1 < M && v[nidx + 1] && find_(nidx) != find_(nidx + 1)) union_(nidx, nidx + 1);
			printf("%d\n", arr[nidx]);
		}
		else {//else v[idx] = 1
			v[idx] = 1;
			// bef, aft chck; and union
			if (idx - 1 >= 0 && v[idx - 1] && find_(idx) != find_(idx - 1)) union_(idx - 1, idx);
			if (idx + 1 < M && v[idx + 1] && find_(idx) != find_(idx + 1)) union_(idx, idx + 1);
			printf("%d\n", arr[idx]);
		}	
	}
	return 0;
}