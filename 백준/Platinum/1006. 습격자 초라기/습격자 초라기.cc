#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 10000;
const int INF = 1e9;

int N, maxEnemies, minSquads;
int enemies[MAX_N][2];
bool canCombineHorizontal[MAX_N][2]; // 가로로 특수소대를 배치할 수 있는지 여부
bool canCombineVertical[MAX_N];      // 세로로 특수소대를 배치할 수 있는지 여부
int dpBothRows[MAX_N + 1];             // 양쪽 행 모두 i-1열까지 채운 경우
int dpFirstRowExtra[MAX_N];          // 1행은 i열까지, 2행은 i-1열까지 채운 경우
int dpSecondRowExtra[MAX_N];         // 1행은 i-1열까지, 2행은 i열까지 채운 경우

inline void calculatePossibleCombinations() {
    // 미리 가능한 조합을 계산해두어 반복적인 조건 검사를 줄임
    rep(i, 0, N - 1) {
        canCombineHorizontal[i][0] = (enemies[i][0] + enemies[i + 1][0] <= maxEnemies);
        canCombineHorizontal[i][1] = (enemies[i][1] + enemies[i + 1][1] <= maxEnemies);
    }
    rep(i, 0, N) {
        canCombineVertical[i] = (enemies[i][0] + enemies[i][1] <= maxEnemies);
    }
}

void solveDP(int startIdx) {
    rep(i, startIdx, N) {
        // 기본 전이: 한쪽 행만 추가로 채운 상태에서 나머지 행 추가
        dpBothRows[i + 1] = min(dpFirstRowExtra[i] + 1, dpSecondRowExtra[i] + 1);

        // 세로로 배치 가능한 경우
        if (canCombineVertical[i]) {
            dpBothRows[i + 1] = min(dpBothRows[i + 1], dpBothRows[i] + 1);
        }

        // 가로로 배치 가능한 경우
        if (i > 0 && canCombineHorizontal[i - 1][0] && canCombineHorizontal[i - 1][1]) {
            dpBothRows[i + 1] = min(dpBothRows[i + 1], dpBothRows[i - 1] + 2);
        }

        // 다음 열이 있는 경우만 계산
        if (i < N - 1) {
            // 1행 추가 계산
            dpFirstRowExtra[i + 1] = dpBothRows[i + 1] + 1;
            if (canCombineHorizontal[i][0]) {
                dpFirstRowExtra[i + 1] = min(dpFirstRowExtra[i + 1], dpSecondRowExtra[i] + 1);
            }

            // 2행 추가 계산
            dpSecondRowExtra[i + 1] = dpBothRows[i + 1] + 1;
            if (canCombineHorizontal[i][1]) {
                dpSecondRowExtra[i + 1] = min(dpSecondRowExtra[i + 1], dpFirstRowExtra[i] + 1);
            }
        }
    }
}

void solve() {
    cin >> N >> maxEnemies;

    // 각 행의 적 수 입력
    rep(i, 0, N) cin >> enemies[i][0];
    rep(i, 0, N) cin >> enemies[i][1];

    // 가능한 조합 미리 계산
    calculatePossibleCombinations();

    minSquads = INF;

    // Case 1: 선형 문제로 취급
    dpBothRows[0] = 0;
    dpFirstRowExtra[0] = dpSecondRowExtra[0] = 1;
    solveDP(0);
    minSquads = dpBothRows[N];

    // 원형인 경우에만 추가 케이스 확인
    if (N > 1) {
        bool canConnectFirstRow = (enemies[0][0] + enemies[N - 1][0] <= maxEnemies);
        bool canConnectSecondRow = (enemies[0][1] + enemies[N - 1][1] <= maxEnemies);

        // Case 2: 1행(위쪽 행)의 첫 열과 마지막 열 연결
        if (canConnectFirstRow) {
            dpBothRows[1] = 1;
            dpFirstRowExtra[1] = 2;
            dpSecondRowExtra[1] = (enemies[0][1] + enemies[1][1] <= maxEnemies) ? 1 : 2;
            solveDP(1);
            minSquads = min(minSquads, dpSecondRowExtra[N - 1] + 1);
        }

        // Case 3: 2행(아래쪽 행)의 첫 열과 마지막 열 연결
        if (canConnectSecondRow) {
            dpBothRows[1] = 1;
            dpFirstRowExtra[1] = (enemies[0][0] + enemies[1][0] <= maxEnemies) ? 1 : 2;
            dpSecondRowExtra[1] = 2;
            solveDP(1);
            minSquads = min(minSquads, dpFirstRowExtra[N - 1] + 1);
        }

        // Case 4: 양쪽 행 모두 첫 열과 마지막 열 연결
        if (canConnectFirstRow && canConnectSecondRow) {
            dpBothRows[1] = 0;
            dpFirstRowExtra[1] = dpSecondRowExtra[1] = 1;
            solveDP(1);
            minSquads = min(minSquads, dpBothRows[N - 1] + 2);
        }
    }

    cout << minSquads << '\n';
}

int main() {
    fastio;
    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}