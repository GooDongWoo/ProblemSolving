#include <iostream>
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int arr[3][3], t1, t2;

// 게임 보드의 상태를 확인하는 함수
// 1: 1번 플레이어의 승리, -1: 2번 플레이어의 승리, 0: 승부 결정되지 않음
int checkWinner() {
    // 가로줄 확인
    rep(i, 0, 3) {
        if (arr[i][0] != 0 && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
            return arr[i][0];
    }

    // 세로줄 확인
    rep(i, 0, 3) {
        if (arr[0][i] != 0 && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
            return arr[0][i];
    }

    // 대각선 확인 (왼쪽 위 -> 오른쪽 아래)
    if (arr[0][0] != 0 && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
        return arr[0][0];

    // 대각선 확인 (오른쪽 위 -> 왼쪽 아래)
    if (arr[0][2] != 0 && arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
        return arr[0][2];

    return 0; // 승자 없음
}

// 미니맥스 알고리즘을 사용한 최적의 결과 계산
// 현재 플레이어 관점에서의 최적 결과를 반환
// 반환값: 1(승리), 0(무승부), -1(패배)
int minimax(int depth, int isMaximizing) {
    // 승자 확인
    int winner = checkWinner();
    if (winner != 0)
        return winner; // 누군가 이미 이겼으면 그 결과 반환

    // 빈 칸이 없으면 무승부
    bool isFullBoard = true;
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            if (arr[i][j] == 0) {
                isFullBoard = false;
                break;
            }
        }
        if (!isFullBoard) break;
    }

    if (isFullBoard)
        return 0; // 무승부

    // 최대화 플레이어(플레이어 1)
    if (isMaximizing) {
        int bestScore = -2;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1; // 플레이어 1의 수
                    int score = minimax(depth + 1, false);
                    arr[i][j] = 0; // 원상복귀
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    }
    // 최소화 플레이어(플레이어 -1)
    else {
        int bestScore = 2;
        rep(i, 0, 3) {
            rep(j, 0, 3) {
                if (arr[i][j] == 0) {
                    arr[i][j] = -1; // 플레이어 -1의 수
                    int score = minimax(depth + 1, true);
                    arr[i][j] = 0; // 원상복귀
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

int main() {
    // 게임 보드 초기화
    rep(i, 0, 3) {
        rep(j, 0, 3) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                arr[i][j] = -1; // 2를 -1로 변환 (2번 플레이어)
                t2++;
            }
            else if (arr[i][j] == 1) {
                t1++; // 1번 플레이어
            }
        }
    }

    // 현재 플레이어 결정
    // 보통 1번 플레이어(1)가 선공, 2번 플레이어(-1)가 후공
    // 두 플레이어의 돌 수가 같으면 1번 플레이어 차례, 다르면 2번 플레이어 차례
    int currentPlayer = (t1 == t2) ? 1 : -1;
    bool isMaximizing = (currentPlayer == 1);

    // 게임 결과 계산
    int result = minimax(0, isMaximizing);

    // 결과 해석
    // 현재 플레이어가 1이면 결과 그대로, -1이면 결과 부호 반전
    if (currentPlayer == -1) {
        result = -result;
    }

    // 현재 플레이어 관점에서의 결과 출력
    if (result > 0)
        cout << "W"; // 승리 (Win)
    else if (result == 0)
        cout << "D"; // 무승부 (Draw)
    else
        cout << "L"; // 패배 (Lose)

    return 0;
}