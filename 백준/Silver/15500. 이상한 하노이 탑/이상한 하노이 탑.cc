#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, cnter;
vector<int> arr[3];
string ans = "";
int main() {
	fastio;
	cin >> N;
	int a;
	rep(i, 0, 3) {
		arr[i].reserve(N);
	}
	rep(i, 0, N) {
		cin >> a;
		arr[0].push_back(a);
	}
	int maxV = N;
	while (arr[2].size() != N) {
		int n1, n2;
		n1 = arr[0].size();
		n2 = arr[1].size();
		bool found = 0;
		rep(i, 0, n1) {
			if (arr[0][i] == maxV) {
				found = 1;
				while (arr[0].size() != i + 1) {
					arr[1].push_back(arr[0].back());
					arr[0].pop_back();
					ans += "1 2\n";
					cnter++;
				}
				arr[0].pop_back();
				arr[2].push_back(maxV);
				ans += "1 3\n";
				cnter++;
				break;
			}
		}
		if (!found) {
			rep(i, 0, n2) {
				if (arr[1][i] == maxV) {
					while (arr[1].size() != i + 1) {
						arr[0].push_back(arr[1].back());
						arr[1].pop_back();
						ans += "2 1\n";
						cnter++;
					}
					arr[1].pop_back();
					arr[2].push_back(maxV);
					ans += "2 3\n";
					cnter++;
					break;
				}
			}
		}
		maxV--;
	}
	printf("%d\n%s", cnter, ans.c_str());
}