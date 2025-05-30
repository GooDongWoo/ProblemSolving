#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

struct pp {
	int idx, sc[4];
	bool chck;
};

pp arr[200000];
int N;

bool comp0(const pp& a, const pp& b) {
	return tie(b.sc[0], a.idx) < tie(a.sc[0], b.idx);
}
bool comp1(const pp& a, const pp& b) {
	return tie(b.sc[1], a.idx) < tie(a.sc[1], b.idx);
}
bool comp2(const pp& a, const pp& b) {
	return tie(b.sc[2], a.idx) < tie(a.sc[2], b.idx);
}
bool comp3(const pp& a, const pp& b) {
	return tie(b.sc[3], a.idx) < tie(a.sc[3], b.idx);
}

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i].idx >> arr[i].sc[0] >> arr[i].sc[1] >> arr[i].sc[2] >> arr[i].sc[3];
	sort(arr, arr + N, comp0);
	int idx = 0;
	while (arr[idx].chck) {
		idx++;
	}
	arr[idx].chck = 1;
	printf("%d ", arr[idx].idx);
	sort(arr, arr + N, comp1);
	idx = 0;
	while (arr[idx].chck) {
		idx++;
	}
	arr[idx].chck = 1;
	printf("%d ", arr[idx].idx);
	sort(arr, arr + N, comp2);
	idx = 0;
	while (arr[idx].chck) {
		idx++;
	}
	arr[idx].chck = 1;
	printf("%d ", arr[idx].idx);
	sort(arr, arr + N, comp3);
	idx = 0;
	while (arr[idx].chck) {
		idx++;
	}
	arr[idx].chck = 1;
	printf("%d ", arr[idx].idx);
	return 0;
}