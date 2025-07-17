#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, K, year;
bool v[2000][2000];
queue<pair<int, int>> q;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };


#define SIZE 4000000
int parent[SIZE], childs[SIZE];

void init() {
	rep(i, 0, SIZE) {
		parent[i] = i;
		childs[i] = 1;
	}
}

int mfind(int num) {
	if (parent[num] != num) {
		parent[num] = mfind(parent[num]);
	}
	return parent[num];
}

void munion(int a, int b) {
	int pa, pb;
	pa = mfind(a);
	pb = mfind(b);
	if (pa == pb) {
		return;
	}
	if (childs[pa] < childs[pb]) {
		swap(pa, pb);
	}
	childs[pa] += childs[pb];
	parent[pb] = pa;
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	cin >> N >> K;
	int a, b;
	rep(i, 0, K) {
		cin >> a >> b;
		a--; b--;
		q.push({ a,b });
		v[a][b] = 1;
	}

	while (K > 1) {
 		int miniLen = q.size();
		rep(i, 0, miniLen) {// 인접한 경우 union
			int cy, cx;
			auto curp = q.front();q.pop();
			q.push(curp);
			cy = curp.first;
			cx = curp.second;	
			rep(i, 0, 4) {
				int dy, dx, ny, nx;
				dy = dys[i]; dx = dxs[i];
				ny = cy + dy;
				nx = cx + dx;
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
					continue;
				}
				if (v[ny][nx] == 1 && (mfind(N * cy + cx) != mfind(N * ny + nx))) {
					munion(N * cy + cx, N * ny + nx);
					K--;
				}
			}
		}

		if (K <= 1) {// K==1이면 최소 시간임;
			cout << year;
			return 0;
		}
		year++;

		rep(i, 0, miniLen) {// BFS하면서 v==0 -> 흡수, v==1&& find != find -> union
			int cy, cx;
			auto curp = q.front();q.pop();
			cy = curp.first;
			cx = curp.second;

			rep(i, 0, 4) {
				int dy, dx, ny, nx;
				dy = dys[i]; dx = dxs[i];
				ny = cy + dy;
				nx = cx + dx;
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
					continue;
				}
				if (v[ny][nx] == 1) {
					if (mfind(N * cy + cx) != mfind(N * ny + nx)) {
						munion(N * cy + cx, N * ny + nx);
						K--;
					}
					else {
						continue;
					}
				}
				else {
					v[ny][nx] = 1;
					q.push({ ny,nx });
					munion(N * cy + cx, N * ny + nx);
				}
			}
		}
	}
	cout << year;
	return 0;
}