#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int y, x, k, d;
};

int N, M, K;
int mat[1000][1000];
int visited[1000][1000][11]; 
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) mat[i][j] = s[j] - '0';
    }

    queue<Node> q;
    q.push({0, 0, 0, 1});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        if (cur.y == N - 1 && cur.x == M - 1) {
            cout << cur.d;
            return 0;
        }

        bool isDay = cur.d % 2 != 0;

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if (mat[ny][nx] == 0) { // 빈 공간
                if (!visited[ny][nx][cur.k]) {
                    visited[ny][nx][cur.k] = cur.d + 1;
                    q.push({ny, nx, cur.k, cur.d + 1});
                }
            } else { // 벽
                if (cur.k < K && !visited[ny][nx][cur.k + 1]) {
                    if (isDay) { 
                        visited[ny][nx][cur.k + 1] = cur.d + 1;
                        q.push({ny, nx, cur.k + 1, cur.d + 1});
                    } else { 
                        q.push({cur.y, cur.x, cur.k, cur.d + 1});
                    }
                }
            }
        }
    }

    cout << -1;
    return 0;
}