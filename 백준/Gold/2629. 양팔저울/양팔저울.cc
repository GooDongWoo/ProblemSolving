#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <random>  

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MAX = 30001;
const int ZERO = 15000;
int N, M, arr[30];
vector<bool> dp1(MAX), dp2(MAX);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N)
	{
		cin >> arr[i];
		rep(j, 0, MAX)
		{
			if (dp1[j])
			{
				dp2[j] = true;
				if (j - arr[i] >= 0)
					dp2[j - arr[i]] = true;
				if (j + arr[i] < MAX)
					dp2[j + arr[i]] = true;
			}
		}
		dp2[ZERO - arr[i]] = true;
		dp2[ZERO + arr[i]] = true;
		dp1.swap(dp2);
	}
	cin >> M;
	rep(i, 0, M)
	{
		int target;
		cin >> target;
		cout << ((target <= ZERO && dp1[ZERO + target]) ? "Y " : "N ");
	}
	return 0;
}