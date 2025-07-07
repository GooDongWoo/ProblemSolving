#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int N, M, aft[1000001], bef[1000001], inp[500000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N >> M;
	rep(i, 0, N) {
		cin >> inp[i];
	}
	rep(i, 0, N) {
		bef[inp[i]] = inp[(i - 1 + N) % N];
		aft[inp[i]] = inp[(i + 1 + N) % N];
	}
	string cmd;
	rep(i, 0, M) {
		cin >> cmd;
		if (cmd == "BN") {
			int a, b;
			cin >> a >> b;
			int aftN = aft[a];

			bef[aftN] = b;
			aft[a] = b;

			bef[b] = a;
			aft[b] = aftN;

			printf("%d\n", aftN);
		}
		else if (cmd == "BP") {
			int a, b;
			cin >> a >> b;
			int befN = bef[a];

			aft[befN] = b;
			bef[a] = b;

			bef[b] = befN;
			aft[b] = a;

			printf("%d\n", befN);
		}
		else if (cmd == "CN") {
			int a;
			cin >> a;
			int aftN = aft[a];

			bef[aft[aftN]] = a;
			aft[a] = aft[aftN];

			printf("%d\n", aftN);
		}
		else if (cmd == "CP") {
			int a;
			cin >> a;
			int befN = bef[a];

			aft[bef[befN]] = a;
			bef[a] = bef[befN];

			printf("%d\n", befN);
		}
		else {
			return 1;
		}
	}
	return 0;
}