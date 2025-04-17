#include <iostream>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define LL long long

using namespace std;

int N, cnter[500][500];
char arr[500][500];
int dys[] = { 1,1,0,-1,-1,-1,0,1 };
int dxs[] = { 0,1,1,1,0,-1,-1,-1 };
bool rangeChck(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < N);
}
int chck(int r, int c) {
	int tot = 0;
	int cnt = 0;
	rep(dd, 0, 8) {
		int ny = r, nx = c;
		ny += dys[dd];
		nx += dxs[dd];
		while (rangeChck(ny, nx) && arr[ny][nx] == 'W') {
			cnt++;
			ny += dys[dd];
			nx += dxs[dd];
		}
		if (rangeChck(ny, nx) && cnt != 0 && arr[ny][nx] == 'B') {
			tot += cnt;
		}
		cnt = 0;
	}
	return tot;
}

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		rep(j, 0, N) {
			arr[i][j] = tmp[j];
		}
	}

	rep(i, 0, N) {
		rep(j, 0, N) {
			if (arr[i][j] != '.')
				continue;
			cnter[i][j] += chck(i, j);
		}
	}
	int maxr = 0, maxc = 0, maxval = cnter[0][0];
	rep(i, 0, N) {
		rep(j, 0, N) {
			if (maxval < cnter[i][j]) {
				maxval = cnter[i][j];
				maxr = i;
				maxc = j;
			}
		}
	}
	if (maxval == 0)
		printf("PASS\n");
	else
		printf("%d %d\n%d", maxc, maxr, maxval);
}