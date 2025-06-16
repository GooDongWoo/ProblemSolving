#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, P, K, D;
	cin >> N >> P >> K >> D;

	vector<int> arr(N, 0);

	if (D == 1 && K > 1) {
		int top_score = P / K;
		int remainder = P % K;

		for (int i = 0; i < K; i++) {
			arr[i] = top_score;
		}

		if (remainder > 0) {
			if (N == K) {
				cout << "Wrong information\n";
				return 0;
			}

			for (int i = K; i < N && remainder > 0; i++) {
				int give = min(remainder, top_score - 1);
				arr[i] = give;
				remainder -= give;
			}

			if (remainder > 0) {
				cout << "Wrong information\n";
				return 0;
			}
		}
	}
	else {
		for (int i = 0; i < D; i++) {
			arr[i] = D - 1 - i;
		}

		int left = P - ((D - 1) * D / 2);
		if (left < 0) {
			cout << "Wrong information\n";
			return 0;
		}

		arr[0] += left;
	}

	set<int> distinct;
	for (int i = 0; i < K; i++) {
		distinct.insert(arr[i]);
	}

	if (distinct.size() == D) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << "\n";
		}
	}
	else {
		cout << "Wrong information\n";
	}

	return 0;
}