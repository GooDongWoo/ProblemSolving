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

typedef struct Item {
	int w, end, befn;
	bool operator>(const Item& o) const{
		return(w > o.w);
	}
};

int T, N, M, TS, S, G, H, v[2000], targets[100], bef[2000], TW;
vector<vector<pair<int, int>>> adjv(2000);

int main() {
	fastio;
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> M >> TS;
		cin >> S >> G >> H; S--; G--; H--;
		memset(v, 0, sizeof(v));
		memset(bef, 0, sizeof(bef));
		rep(i, 0, N)adjv[i].clear();
		rep(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c; a--; b--;
			adjv[a].push_back({ c, b });
			adjv[b].push_back({ c, a });
			if (((a == G) && (b == H)) || ((a == H) && (b == G))) TW = c;
		}
		rep(i, 0, TS) {
			cin >> targets[i]; targets[i]--;
		}
		sort(targets, targets + TS);
		priority_queue<Item,vector<Item>,greater<>> pq;
		pq.push({ 0,S,S });
		while (pq.size()) {
			auto curp = pq.top(); pq.pop();
			int w = curp.w, end = curp.end, befn = curp.befn;
			if (v[end]) continue;
			v[end] = 1;
			bef[end] = befn;
			rep(i, 0, adjv[end].size()) {
				auto nxtp = adjv[end][i];
				int nh = nxtp.fi, nxt = nxtp.se;
				if (v[nxt])continue;
				pq.push({ w + nh,nxt,end });
			}
			if ((end == G) || (end == H)) {
				int inxt, inow;
				if (end == G) { inxt = H; inow = G; }
				else { inxt = G; inow = H; }
				v[inxt] = 1; bef[inxt] = inow;
				end = inxt;
				w += TW;
				rep(i, 0, adjv[end].size()) {
					auto nxtp = adjv[end][i];
					int nh = nxtp.fi, nxt = nxtp.se;
					if (v[nxt])continue;
					pq.push({ w + nh,nxt,end });
				}
			}
		}
		vector<int> anslist;
		rep(i, 0, TS) {
			int cur = targets[i];
			while (cur != S) {
				int befbef = bef[cur];
				if ((cur == G && befbef == H) || (cur == H && befbef == G)) {
					anslist.push_back(targets[i]);
				}
				cur = befbef;
			}
		}
		rep(i, 0, anslist.size()) printf("%d ", anslist[i] + 1);
		printf("\n");
	}
}