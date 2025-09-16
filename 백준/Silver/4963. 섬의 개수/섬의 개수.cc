#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using LL = long long;

int dys[] = { 1,1,0,-1,-1,-1,0,1 };
int dxs[] = { 0,1,1,1,0,-1,-1,-1 };
int W, H, arr[52][52], v[52][52], ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		ans = 0;
		cin >> W >> H;
		if (W == 0 && H == 0) {
			return 0;
		}
		rep(i, 1, H + 1) {
			rep(j, 1, W + 1) {
				cin >> arr[i][j];
			}
		}
		rep(i, 1, H + 1) {
			rep(j, 1, W + 1) {
				if (v[i][j] == 1 || arr[i][j] == 0) {
					continue;
				}
				ans++;
				queue<pair<int, int>> q;
				q.push({ i,j });
				v[i][j] = 1;
				while (q.size()) {
					auto curp = q.front(); q.pop();
					int ch = curp.first;
					int cw = curp.second;
					rep(step, 0, 8) {
						int nh = ch + dys[step];
						int nw = cw + dxs[step];
						if (v[nh][nw] == 1 || arr[nh][nw] == 0) {
							continue;
						}
						v[nh][nw] = 1;
						q.push({ nh,nw });
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}