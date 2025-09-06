#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Item {
	int queryNum, i, j, outputIdx;
	bool operator<(const Item& b) const {
		return queryNum < b.queryNum;
	}
};
int N, M, arr[100001];
LL bit[100001];
vector<Item> qList;
vector<pair<int, int>> uList;
vector<LL> anslist;

void update(int idx, int val) {
	while (idx <= N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
	return;
}

LL query(int idx) {
	LL ret = 0;
	while (idx > 0) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	cin >> M;
	int outputIdx = 0;
	rep(i, 0, M) {
		int ctype;
		cin >> ctype;
		if (ctype == 1) {
			int idx, val;
			cin >> idx >> val;
			uList.push_back({ idx,val });
		}
		else {
			int k, start, end;
			cin >> k >> start >> end;
			qList.push_back({ k,start,end,outputIdx++ });
		}
	}
	sort(qList.begin(), qList.end());
	int qidx = 0;
	anslist.resize(outputIdx);
	uList.push_back({ 1,0 }); // padding
	rep(step, 0, uList.size()) {
		while (qidx < qList.size() && qList[qidx].queryNum <= step) {// int queryNum, i, j, outputIdx;
			anslist[qList[qidx].outputIdx] = query(qList[qidx].j) - query(qList[qidx].i) + arr[qList[qidx].i];
			qidx++;
		}
		update(uList[step].first, uList[step].second - arr[uList[step].first]);
		arr[uList[step].first] = uList[step].second;
	}
	rep(i, 0, outputIdx) {
		cout << anslist[i] << '\n';
	}
	return 0;
}