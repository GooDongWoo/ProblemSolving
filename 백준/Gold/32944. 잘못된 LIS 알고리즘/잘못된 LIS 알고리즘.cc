#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
vector<int> dq;  // deque 대신 vector 사용 (cache locality 향상)
vector<int> arr;

int main() {
	fastio;
	cin >> N >> M >> K;
	if (M == N) {
		printf("-1");
	}
	else {
		// 메모리 재할당 최소화를 위한 reserve
		arr.reserve(N);
		dq.reserve(N - K);
		
		arr.resize(K);
		rep(i, 1, K)
			arr[i - 1] = i;
		arr[K - 1] = N;
		
		rep(i, K, N)
			dq.push_back(i);
		
		vector<int> tmp;
		tmp.reserve(M - K + 1);  // 메모리 재할당 최소화
		
		rep(i, 0, M - K + 1) {
			tmp.push_back(dq.back());
			dq.pop_back();
		}
		
		sort(tmp.begin(), tmp.end());
		
		// 더 효율적인 삽입 (iterator 사용)
		arr.insert(arr.end(), tmp.begin(), tmp.end());
		
		// 역순으로 남은 원소들 추가
		while (!dq.empty()) {
			arr.push_back(dq.back());
			dq.pop_back();
		}
		
		// 더 빠른 출력 (단일 문자열로 구성 후 출력)
		for (size_t i = 0; i < arr.size(); ++i) {
			printf("%d", arr[i]);
			if (i < arr.size() - 1) printf(" ");
		}
	}
	
	return 0;
}