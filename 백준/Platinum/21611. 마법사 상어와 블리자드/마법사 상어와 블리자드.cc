#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<string>
#include<cstring>

using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

int mat[49][49], mat2idx[49][49], maxCnt, N, M, ans[3];
int direction2idx[5] = { 0,2,0,3,1 };
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
queue<int> q;

/// <summary>
/// d와 s가 있을 때 mat2idx에서 해당 위치에서 idx가 무엇들인지 벡터로 반환해준다.
/// </summary>
vector<int> GetIndice(int d, int s) {
	vector<int> ret;
	int cy = N / 2;
	int cx = N / 2;
	int dir = direction2idx[d];

	for (int k = 1; k <= s; ++k) {
		cy += dys[dir];
		cx += dxs[dir];
		// 격자 범위 내에 있는지 확인
		if (cy >= 0 && cy < N && cx >= 0 && cx < N) {
			ret.push_back(mat2idx[cy][cx]);
		}
	}
	
	// 인덱스를 오름차순으로 정렬하여 삭제 시 순서가 꼬이지 않도록 보장
	sort(ret.begin(), ret.end());
	return ret;
}

/// <summary>
/// 전역변수 q에서 vec[idx]에 해당하는 idx들을 없애고 다시 q에 넣는다.
/// </summary>
void RemoveIndice(vector<int>& vec) {
	int sz = q.size();
	int v_idx = 0;
	
	for (int i = 0; i < sz; ++i) {
		int val = q.front();
		q.pop();
		
		// vec에 포함된 인덱스라면 큐에 다시 넣지 않음(삭제)
		if (v_idx < vec.size() && i == vec[v_idx]) {
			v_idx++; 
		}
		else {
			q.push(val);
		}
	}
}

/// <summary>
/// 전역변수 q에서 연속으로 같은 숫자가 4개 이상 나오는 index들을 전부 vec에 넣고 ret한다.
/// </summary>
vector<int> CntSeq4Indice() {
	vector<int> ret;
	vector<int> temp;
	int sz = q.size();

	// 큐를 유지하기 위해 순회하며 복사
	for (int i = 0; i < sz; ++i) {
		temp.push_back(q.front());
		q.push(q.front());
		q.pop();
	}

	if (temp.empty()) return ret;

	int start = 0;
	for (int i = 1; i <= temp.size(); ++i) {
		if (i == temp.size() || temp[i] != temp[start]) {
			int len = i - start;
			if (len >= 4) {
				for (int j = start; j < i; ++j) {
					ret.push_back(j);
				}
				// 터진 구슬의 개수를 정답 배열에 누적 (구슬 번호는 1, 2, 3 -> 인덱스 0, 1, 2)
				ans[temp[start] - 1] += len;
			}
			start = i;
		}
	}
	return ret;
}

/// <summary>
/// 회오리로 mat을 방문하면서 mat2idx를 완성하고 방문하는 순서대로 초기 q에 값을 넣는다. 값이 0이면 넣는 것을 stop한다.
/// </summary>
void MakeMat2Idx() {
	maxCnt = N * N - 1; // 구슬이 들어갈 수 있는 최대 칸 수 초기화
	int cy = N / 2, cx = N / 2;
	int dir = 3; // 초기 방향은 좌측 (dys[3]=0, dxs[3]=-1)
	int len = 1;
	int cur_idx = 0;
	bool stop_push = false;

	while (true) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < len; ++j) {
				cy += dys[dir];
				cx += dxs[dir];
				
				if (cy < 0 || cx < 0 || cy >= N || cx >= N) return;
				
				mat2idx[cy][cx] = cur_idx++; // 0번 인덱스부터 매핑
				
				if (mat[cy][cx] == 0) {
					stop_push = true; // 값이 0이면 이후부터는 큐에 넣지 않음
				}
				if (!stop_push) {
					q.push(mat[cy][cx]);
				}
			}
			// 나선형 방향 전환: 좌 -> 하 -> 우 -> 상 (3 -> 0 -> 1 -> 2)
			dir = (dir + 1) % 4;
		}
		len++; // 2번 방향을 바꿀 때마다 이동 길이가 1씩 증가
	}
}

/// <summary>
/// q에 들어있는 group을 변경한다.(그룹의 아이템 개수, 그룹 구슬 번호) 변환할 때 maxCnt보다 많으면 무시한다.
/// </summary>
void ChangeGroupItems() {
	vector<int> temp;
	int sz = q.size();
	for (int i = 0; i < sz; ++i) {
		temp.push_back(q.front());
		q.pop();
	}

	if (temp.empty()) return;

	int start = 0;
	for (int i = 1; i <= temp.size(); ++i) {
		if (i == temp.size() || temp[i] != temp[start]) {
			int len = i - start;
			int num = temp[start];
			
			// maxCnt(N*N-1)를 초과하면 무시
			if (q.size() < maxCnt) q.push(len);
			if (q.size() < maxCnt) q.push(num);
			
			start = i;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M;
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> mat[i][j];
		}
	}

	MakeMat2Idx();
	// 이미 q에 값들이 들어 있다.

	rep(i, 0, M) {
		int d, s;
		cin >> d >> s;
		auto indice = GetIndice(d, s);
		RemoveIndice(indice);

		indice = CntSeq4Indice();
		while (indice.size()) {
			RemoveIndice(indice);
			indice = CntSeq4Indice();
		}

		ChangeGroupItems();
	}

	cout << (ans[0] * 1) + (ans[1] * 2) + (ans[2] * 3);
	return 0;
}