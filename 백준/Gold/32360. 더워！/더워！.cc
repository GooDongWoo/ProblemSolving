#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

const int MAX_N = 1000;
const int MAX_M = 1000;
const int INF = 1e8;

// 방향 배열 (0번은 제자리, 1~4번은 상하좌우)
constexpr int dx[] = {0, 0, 0, 1, -1};
constexpr int dy[] = {0, 1, -1, 0, 0};

// 전역 변수
char mat[MAX_N][MAX_M+1];
int visited[MAX_N][MAX_M];

// 큐에 들어갈 상태 정보
struct State {
    int y, x, damage;
    
    State() = default;
    State(int _y, int _x, int _d) : y(_y), x(_x), damage(_d) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k, c;
    cin >> n >> m >> k >> c;
    
    // visited 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            visited[i][j] = INF;
        }
    }
    
    int start_y = -1, start_x = -1;
    
    // 맵 입력받기
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S') {
                start_y = i;
                start_x = j;
            }
        }
    }
    
    // BFS 큐
    queue<State> q;
    q.push(State(start_y, start_x, 0));
    visited[start_y][start_x] = 0;
    
    int time = 0;
    
    while (!q.empty()) {
        // 현재 타임에 처리할 큐의 크기
        int size = q.size();
        
        for (int i = 0; i < size; i++) {
            State curr = q.front();
            q.pop();
            
            int y = curr.y;
            int x = curr.x;
            int dc = curr.damage;
            
            // 목적지 도달
            if (mat[y][x] == 'E') {
                cout << time << endl;
                return 0;
            }
            
            // 모든 방향 탐색
            for (int dir = 0; dir < 5; dir++) {
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                
                // 경계 및 벽 체크
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || mat[ny][nx] == '#') {
                    continue;
                }
                
                // 데미지 계산
                int new_damage = dc;
                
                if (mat[ny][nx] == '.' || mat[ny][nx] == 'E') {
                    new_damage += c;
                } else {
                    // 힐링 지점
                    new_damage -= k;
                    if (new_damage < 0) {
                        new_damage = 0;
                    }
                }
                
                // 데미지 체크
                if (new_damage >= 100) {
                    continue;
                }
                
                // 더 나은 경로 발견
                if (new_damage < visited[ny][nx]) {
                    visited[ny][nx] = new_damage;
                    q.push(State(ny, nx, new_damage));
                }
            }
        }
        
        time++;
    }
    
    cout << -1 << endl;
    return 0;
}