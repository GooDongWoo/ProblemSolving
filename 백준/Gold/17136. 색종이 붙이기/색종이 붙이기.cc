#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mat[10][10];
int paper[6] = { 0, 5, 5, 5, 5, 5 }; // 1번~5번 색종이 개수 (인덱스 1~5 사용)
int ans = 1e9;

// (y, x) 위치에 sz 크기의 색종이를 붙일 수 있는지 확인
bool canAttach(int y, int x, int sz) {
    if (y + sz > 10 || x + sz > 10) return false;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (mat[y + i][x + j] == 0) return false;
        }
    }
    return true;
}

// 색종이를 붙이거나(0) 떼는(1) 함수
void attach(int y, int x, int sz, int val) {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            mat[y + i][x + j] = val;
        }
    }
}

// x, y: 탐색 시작 좌표, cnt: 현재 사용한 색종이 개수
void dfs(int y, int x, int cnt) {
    // [최적화 1] 현재 개수가 이미 찾은 답보다 크거나 같으면 중단
    if (cnt >= ans) return;

    // x가 범위를 벗어나면 다음 줄로
    if (x == 10) {
        dfs(y + 1, 0, cnt);
        return;
    }

    // y가 범위를 벗어나면 모든 탐색 종료 (성공)
    if (y == 10) {
        ans = min(ans, cnt);
        return;
    }

    // 0이면 다음 칸으로 넘어감
    if (mat[y][x] == 0) {
        dfs(y, x + 1, cnt);
        return;
    }

    // 1인 경우: 큰 색종이(5)부터 붙여봄 (큰 거부터 붙여야 빠르게 채우고 가지치기 유리)
    for (int sz = 5; sz >= 1; sz--) {
        if (paper[sz] > 0 && canAttach(y, x, sz)) {
            attach(y, x, sz, 0); // 붙임 (0으로 만듦)
            paper[sz]--;
            
            // [구조적 최적화]
            // 색종이를 붙였으므로, x + 1이 아니라
            // 해당 색종이의 오른쪽 끝 다음 칸, 혹은 그냥 x+sz가 아닌
            // 단순하게 x+1을 호출해도 어차피 앞부분은 0이 되어 건너뛰게 됨.
            // (여기서는 x + sz로 건너뛰어도 되지만, x+1로 해도 
            //  앞의 0체크 로직 때문에 빠르게 스킵됨)
            dfs(y, x + 1, cnt + 1); 

            paper[sz]++;
            attach(y, x, sz, 1); // 뗌 (원상복구)
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> mat[i][j];
        }
    }

    dfs(0, 0, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}