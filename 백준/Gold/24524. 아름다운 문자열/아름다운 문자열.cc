#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

string word, target;
unordered_map<char, int> dict;
int cnter, N;

int main() {
	fastio;
	cin >> word >> target;
	N = target.size();
	rep(i, 0, N)
		dict[target[i]] = i;
	vector<queue<int>> arr(N);
	rep(i, 0, word.size()) {
		char curc = word[i];
		if (dict.find(curc) != dict.end()) 
			arr[dict[curc]].push(i);
	}
	bool Flag = true;
	while (Flag) {
		if (!arr[0].size()) break;
		int curv = arr[0].front(); arr[0].pop();
		rep(i, 1, N) {
			while (arr[i].size() && arr[i].front() <= curv) {
				arr[i].pop();
			}
			if (arr[i].size() && arr[i].front() > curv) {
				curv = arr[i].front(); arr[i].pop();
			}
			else {
				Flag = false;
				break;
			}
		}
		if (Flag) cnter++;
	}
	printf("%d\n", cnter);
	return 0;
}