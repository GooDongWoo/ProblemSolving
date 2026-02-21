#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>
#include <stdexcept>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

struct Node {
	int left, right, parent;
	Node() : left(-1), right(-1), parent(-1) {
	}
};

int N, curX, curY, levelFirst[10001], width[10001], ans, ansVal;
Node nodes[10001];

void F(int idx) {
	// 해당 노드 왔다는 것은 무조건 내려왔다는 것
	curY++;
	//1 go left
	if (nodes[idx].left != -1) {
		F(nodes[idx].left);
	}

	//2 cur val (main logic)
	curX++;
	if (levelFirst[curY] == 0) {// 이전에 한번도 이 레벨 X
		levelFirst[curY] = curX;
	}
	width[curY] = max(width[curY], curX - levelFirst[curY] + 1);
	if (width[curY] > ansVal) {
		ansVal = width[curY];
		ans = curY;
	}
	else if (width[curY] == ansVal) {
		ans = min(ans, curY);
	}

	//3 go right
	if (nodes[idx].right != -1) {
		F(nodes[idx].right);
	}

	// 다끝났으니 올라가야지
	curY--;
	return;
}

int Find_(int idx) {
	while (nodes[idx].parent != idx) {
		idx = nodes[idx].parent;
	}
	return idx;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	rep(i, 1, N + 1) {
		nodes[i].parent = i;
	}
	rep(i, 0, N) {
		int n, l, r;
		cin >> n >> l >> r;
		nodes[n].left = l;
		nodes[n].right = r;
		if (l != -1) {
			nodes[l].parent = n;
		}
		if (r != -1) {
			nodes[r].parent = n;
		}
	}
	int startIdx = Find_(1);
	F(startIdx);
	cout << ans << ' ' << ansVal;
	return 0;
}