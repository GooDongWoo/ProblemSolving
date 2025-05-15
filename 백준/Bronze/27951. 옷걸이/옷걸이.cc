#include <iostream>
#include <vector>
#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int N, U, D, arr[1000000], cnts[3];

int main() {
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
		cnts[arr[i] - 1]++;
	}
	cin >> U >> D;
	if (cnts[2] + cnts[0] >= U && cnts[2] + cnts[1] >= D) {
		printf("YES\n");
		int cnt = 0;
		int LIMIT = U - cnts[0];
		rep(i, 0, N) {
			if (arr[i] == 1)
				printf("U");
			else if (arr[i] == 2)
				printf("D");
			else {
				if (cnt >= LIMIT)
					printf("D");
				else
					printf("U");
				cnt++;
			}
		}
		return 0;
	}
	else {
		printf("NO\n");
		return 0;
	}
}