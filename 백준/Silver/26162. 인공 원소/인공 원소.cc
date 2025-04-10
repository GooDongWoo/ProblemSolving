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
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int N, arr[200];
vector<int> primes;
int main() {
	fastio;
	rep(i, 2, 200)
		arr[i] = 1;
	rep(i, 2, 200) {
		if (arr[i] > 0) {
			primes.push_back(i);
			for (int j = i * i; j < 200; j += i) {
				arr[j] = 0;
			}
		}
	}
	cin >> N;
	rep(i, 0, N) {
		int a;
		bool flag = 0;
		cin >> a;
		for(const int& x:primes){
			if (a - x < 0)
				continue;
			if (arr[a - x]) {
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}