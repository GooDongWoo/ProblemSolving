#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int N, M, P[100000], Rank[100000], Cnum, Hnum, K;
unordered_set <int> s1;
void init() {
	rep(i, 0, N) {
		P[i] = i;
		Rank[i] = 1;
	}
}
int find_(int num) {
	if (P[num] != num)
		return P[num] = find_(P[num]);
	return P[num];
}

void union_(int a, int b) {
	int pa, pb;
	pa = find_(a);
	pb = find_(b);
	if (pa == pb)
		return;
	if (Rank[pa] < Rank[pb])
		swap(pa, pb);
	P[pb] = pa;
	Rank[pa] += Rank[pb];
	return;
}

int main() {
	fastio;
	cin >> N >> M;
	init();
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b; a--; b--;
		union_(a, b);
	}
	rep(i, 0, N)
		find_(i);
	cin >> Cnum >> Hnum >> K; Cnum--; Hnum--;
	int pc, ph;
	pc = find_(Cnum); ph = find_(Hnum);
	vector<int> vlist;
	rep(i, 0, N) {
		int tmp = find_(i);
		if (tmp == pc || tmp == ph)
			continue;
		if (s1.find(tmp) == s1.end()) {
			vlist.push_back(Rank[tmp]);
			s1.insert(tmp);
		}
	}
	sort(vlist.begin(), vlist.end(), greater<>());
	int ans = Rank[pc];
	rep(i, 0, K) {
		if (!(i < vlist.size()))
			break;
		ans += vlist[i];
	}
	printf("%d\n", ans);
}