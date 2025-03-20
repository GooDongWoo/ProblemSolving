#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int N, M, Q, arr[200000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> Q;
	rep(i, 0, M)cin >> arr[i];
	rep(i, 0, Q) {
		string qq;
		int a, b;
		cin >> qq;
		if (qq == "assign") {
			cin >> a >> b;
			arr[a - 1] = arr[b - 1];
		}
		else if (qq == "swap") {
			cin >> a >> b;
			swap(arr[a - 1], arr[b - 1]);
		}
		else {
			cin >> a;
			arr[a - 1] = 0;
		}
	}
	set <int> s1;
	rep(i, 0, M) {
		if(arr[i]!=0)s1.insert(arr[i]);
	}
	printf("%d\n", s1.size());
	for (auto itr = s1.begin(); itr != s1.end(); itr++) {
		printf("%d\n", *itr);
	}
	return 0;
}