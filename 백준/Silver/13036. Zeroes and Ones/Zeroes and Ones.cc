#include <iostream>
#include <string>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int T, N, arr[100000][2];
string a, b;
int main() {
	cin >> T;
	rep(ttt, 0, T) {
		cin >> N >> a >> b;
		int cost = 0;
		rep(i, 0, N) {
			if (a[i] == '0') arr[i][0] = 0;
			else arr[i][0] = 1;
			if (b[i] == '0') arr[i][1] = 0;
			else arr[i][1] = 1;
		}
		rep(i, 0, N - 1) {
			if (arr[i][0] != arr[i][1]) {
				arr[i][0] ^= 1;
				arr[i+1][0] ^= 1;
				cost++;
			}
		}
		if (arr[N - 1][0] == arr[N - 1][1])printf("%d\n", cost);
		else printf("-1\n");
	}
}