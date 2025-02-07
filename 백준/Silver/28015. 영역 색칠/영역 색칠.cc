#include<iostream>
#include <vector>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

int n, m, arr[100][100], cnter, tmp1, tmp2, idx;


int main(int argc, char** argv)
{
	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> arr[i][j];

	rep(i, 0, n) {
		tmp1 = 0;
		idx = 0;
		int start, end;
		while (idx < m) {
			while (idx < m && arr[i][idx] == 0) { idx++; }
			if (!(idx < m)) break;
			start = idx;
			while (idx < m && arr[i][idx] != 0) { idx++; }
			end = idx;

			int leng = end - start;
			int scolor = (arr[i][start] == 1) ? 1 : 2;
			while (start < end - 1) {
				if (arr[i][start] == scolor && arr[i][start + 1] != scolor) tmp1++;
				start++;
			}
			tmp1++;
		}
		cnter += tmp1;
	}

	printf("%d\n", cnter);

	return 0;

}