#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int T, M;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> M;
		priority_queue<int> maxq;
		priority_queue<int, vector<int>, greater<>> minq;
		vector<int> anslist;
		int a, b;
		cin >> a;
		minq.push(a);
		anslist.push_back(minq.top());
		for (int i = 2;i < M + 1;i += 2) {
			cin >> a >> b;
			minq.push(a);
			maxq.push(b);
			a = minq.top();minq.pop();
			b = maxq.top();maxq.pop();
			int min1 = min(a, b);
			int max1 = max(a, b);
			maxq.push(min1);
			minq.push(max1);
			anslist.push_back(minq.top());
		}
		cout << anslist.size() << '\n';
		for (int i = 0;i < anslist.size();++i) {
			cout << anslist[i] << ' ';
			if (i % 10 == 9 && i != anslist.size() - 1) {
				cout << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}