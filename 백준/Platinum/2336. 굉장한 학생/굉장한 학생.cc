#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

struct Student {
	int id;
	int ranks[3];
	bool operator<(const Student& other) const {
		return ranks[0] < other.ranks[0];
	}
};

int N, segtree[2000004], ans, temp_rank[500001][3];
Student students[500001];

void update(int idx, int l, int r, int qidx, int val) {
	if (qidx < l || r < qidx) return;
	if (l == r) {
		segtree[idx] = min(segtree[idx], val); 
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, qidx, val);
	update(2 * idx + 1, mid + 1, r, qidx, val);
	segtree[idx] = min(segtree[2 * idx], segtree[2 * idx + 1]);
}

int query(int idx, int l, int r, int ql, int qr) {
	if (qr < l || r < ql || ql > qr) return 1e9;
	if (ql <= l && r <= qr) return segtree[idx];
	int mid = (l + r) / 2;
	return min(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, 4 * (N + 1)) {
		segtree[i] = 1e9;
	}

	rep(i, 0, 3) {
		rep(j, 1, N + 1) {
			int student_id;
			cin >> student_id;
			temp_rank[student_id][i] = j;
		}
	}

	rep(i, 1, N + 1) {
		students[i].id = i;
		students[i].ranks[0] = temp_rank[i][0];
		students[i].ranks[1] = temp_rank[i][1];
		students[i].ranks[2] = temp_rank[i][2];
	}

	sort(students + 1, students + N + 1);
	rep(i, 1, N + 1) {
		update(1, 1, N, students[i].ranks[1], students[i].ranks[2]);
		if (students[i].ranks[1] == 1) {
			ans++;
			continue;
		}
		ans += query(1, 1, N, 1, students[i].ranks[1] - 1) < students[i].ranks[2] ? 0 : 1;
	}
	cout << ans;
	return 0;

}