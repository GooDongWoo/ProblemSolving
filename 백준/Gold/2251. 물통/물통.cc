#define rep(i,a,b) for(int i=a;i<b;++i)

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int ori[3];
vector<int> arr;
set<vector<int>> s1;
set<int> ans;

void bt() {
	if (s1.find(arr) != s1.end())
		return;
	s1.insert(arr);
	if (arr[0] == 0)
		ans.insert(arr[2]);

	// 어디에 무엇을 넣을지 선택하는 과정
	//12,13,21,23,31,32
	rep(i, 0, 3) {
		rep(j, 0, 3) {
			if (i == j) continue; // 같은 곳에서 움직이는것은 안됨
			if (arr[i] == 0) continue; // 움직이려는 곳이 0이면 안되지;

			int pour = arr[i]; // 쏟을려는 물
			int aldy = arr[j]; // 이동된 곳에 이미 있는 물
			int possi = ori[j] - aldy; // 이동될 곳에 최대한 넣을 수 있는 물
			int moving = min(possi, pour);

			//바꾸기
			arr[i] -= moving;
			arr[j] += moving;
			// ㄱㄱ
			bt();
			// 원복
			arr[i] += moving;
			arr[j] -= moving;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	rep(i, 0, 3)
		cin >> ori[i];
	arr = { 0,0,ori[2] };
	bt();
	for (const int& x : ans)
		printf("%d ", x);
	return 0;
}