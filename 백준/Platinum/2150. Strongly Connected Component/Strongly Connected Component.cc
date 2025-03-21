#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int V, E;
// 그래프 정보
vector<vector<int>> adj;  // 인접 리스트

// 타잔 알고리즘 관련 변수들
vector<int> disc;         // 발견 순서 (discovery ct)
vector<int> low;          // 각 정점의 low link 값
vector<bool> inStack;     // 스택에 있는지 여부
stack<int> st;            // 정점을 저장하는 스택
int ct = 0;             // 발견 순서 카운터
vector<vector<int>> SCCs; // 결과 SCC 리스트

// 타잔 알고리즘의 DFS 함수
void tarjanDFS(int u) {
	// 현재 정점의 발견 순서와 low link 값 초기화
	disc[u] = low[u] = ++ct;
	st.push(u);           // 스택에 정점 추가
	inStack[u] = true;    // 스택에 있음을 표시

	// 인접한 모든 정점에 대해
	for (int v : adj[u]) {
		// 아직 방문하지 않은 정점이면
		if (disc[v] == -1) {
			tarjanDFS(v);  // 재귀적으로 DFS 호출
			// 자식에서 갈 수 있는 가장 높은 정점으로 나의 low 값 업데이트
			low[u] = min(low[u], low[v]);
		}
		// 이미 방문했고 스택에 있는 정점이면 (백 엣지)
		else if (inStack[v]) {
			// 이미 방문한 정점 중 가장 빨리 발견된 정점으로 low 값 업데이트
			low[u] = min(low[u], low[v]);
		}
	}

	// SCC의 루트를 찾으면 (발견 순서와 low link 값이 같으면)
	if (low[u] == disc[u]) {
		vector<int> component;  // 새로운 SCC 생성
		int w;
		do {
			w = st.top();       // 스택에서 정점 꺼내기
			st.pop();
			inStack[w] = false; // 스택에서 제거됨을 표시
			component.push_back(w); // SCC에 정점 추가
		} while (w != u);       // 현재 정점까지 꺼내기

		SCCs.push_back(component); // 결과에 SCC 추가
	}
}

// 모든 SCC를 찾는 함수
void findSCCs(int V) {
	disc.assign(V, -1);     // 발견 순서 초기화
	low.assign(V, -1);      // low link 값 초기화
	inStack.assign(V, false); // 스택 상태 초기화
	ct = 0;               // 시간 초기화

	// 모든 정점에 대해 DFS 수행
	rep(i, 0, V) {
		if (disc[i] == -1) {  // 아직 방문하지 않은 정점이면
			tarjanDFS(i);     // DFS 호출
		}
	}
}

int main() {
	cin >> V >> E;
	adj.resize(V);
	rep(i, 0, E) {
		int a, b;
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
	}
	// SCC 찾기
	findSCCs(V);

	// 결과 출력
	printf("%d\n", SCCs.size());
	rep(i, 0, SCCs.size()) sort(SCCs[i].begin(), SCCs[i].end());
	sort(SCCs.begin(), SCCs.end());
	rep(i, 0, SCCs.size()) {
		for (int v : SCCs[i]) {
			printf("%d ", v + 1);
		}
		printf("-1\n");
	}
	return 0;
}