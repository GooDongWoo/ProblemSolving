#include<iostream>
#include <cstring>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, ans, v[10];


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		memset(v, 0, sizeof(v));
		cin >> N;
		int mul = 1;
		int cnt = 0;
		while (cnt < 10){
			int nn = N * mul;
			while (nn) {
				int t = nn % 10;
				nn /= 10;
				if (v[t]) continue;
				else {
					v[t] = 1;
					cnt++;
				}
			}
			mul++;
		}
		mul--;
		printf("#%d %d\n", test_case, N* mul);
	}
	return 0;
}