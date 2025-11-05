#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, arr[1000000], cnter[1000001], ans[1000000];
stack<pair<int, int>> stck;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
		cnter[arr[i]]++;
	}
	rep(i, 0, N) {
		while (stck.size() && stck.top().first <= cnter[arr[N - 1 - i]]) {
			stck.pop();
		}
		ans[N - 1 - i] = ((stck.size() == 0) ? -1: stck.top().second);
		stck.push({ cnter[arr[N - 1 - i]],arr[N - 1 - i] });
	}
	string resultText = "";
	for (int i = 0; i < N; i++) { resultText += to_string(ans[i]); resultText += " "; }
	cout << resultText;
	return 0;
}