#include <iostream>
#include <algorithm>
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int N, cnter[4], ans, t1, t2;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int a;
	rep(i, 0, N) {
		cin >> a;
		cnter[a]++;
	}
	//3
	t1 = min(cnter[1], cnter[2]);
	t2 = min(cnter[0], cnter[3]);
	ans += 3 * (t1 + t2);
	cnter[1] -= t1; cnter[2] -= t1;
	cnter[0] -= t2; cnter[3] -= t2;


	//2
	t1 = min(cnter[0], cnter[2]);
	t2 = min(cnter[1], cnter[3]);
	ans += 2 * (t1 + t2);
	cnter[0] -= t1; cnter[2] -= t1;
	cnter[1] -= t2; cnter[3] -= t2;

	//1
	t1 = min(cnter[0], cnter[1]);
	t2 = min(cnter[2], cnter[3]);
	ans += (t1 + t2);
	cnter[0] -= t1; cnter[1] -= t1;
	cnter[2] -= t2; cnter[3] -= t2;

	cout << ans;

	return 0;
}