#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

#define fastio ios_base ::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)

int a;
string tmp;
int main() {
	cin >> a;
	while (1) {
		cout << "? 1\n" << flush;
		cin >> tmp;
		if (tmp[0] == 'Y') {
			cout << "! 1" << flush;
			break;
		}
	}
	return 0;
}