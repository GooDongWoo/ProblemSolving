#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, R;
int A[2000], B[40000];

int bs_l(double target) {
	int begin = 0;
	int end = M-1;
	int mid;
	while (begin <= end) {
		mid = (begin + end) / 2;
		if (target < B[mid]){
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}
	return end;
}

int main() {
	cin >> N >> M >> R;
	for (int i = 0;i < N;i++) {
		cin >> A[i];
	}
	for (int i = 0;i < M;i++) {
		cin >> B[i];
	}

	sort(A, A+N);sort(B, B + M);

	vector<int> candidates;

	for (int i = 0;i < N-1;i++) {
		for (int j = i+1;j < N;j++) {
			candidates.push_back(A[j] - A[i]);
		}
	}
	sort(candidates.begin(), candidates.end());
	candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

	double ans = -1.;
	double tmp = 0;
	int idx = 0;
	for (int i = 0; i < candidates.size();i++) {
		idx = bs_l((2. * R) / candidates[i]);
		if (idx < 0) continue;
		tmp = B[idx] * candidates[i] / (2.);
		ans = max(ans, tmp);
	}
	if (ans == -1) {
		printf("%d", (int)ans);
	}
	else {
		printf("%.1f", ans);
	}
}