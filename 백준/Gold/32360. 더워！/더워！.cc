#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

const int INF = 1e8;
const int dy[5] = {0, 1, -1, 0, 0};
const int dx[5] = {0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k, c;
    cin >> n >> m >> k >> c;
    
    vector<string> mat(n);
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    
    // Find starting position
    int start_y = -1, start_x = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'S') {
                start_y = i;
                start_x = j;
                break;
            }
        }
        if (start_y != -1) break;
    }
    
    // BFS with time tracking
    vector<vector<int>> visited(n, vector<int>(m, INF));
    visited[start_y][start_x] = 0;
    
    using State = tuple<int, int, int>; // y, x, damage_count
    vector<State> current_queue = {{start_y, start_x, 0}};
    
    int time = 0;
    while (!current_queue.empty()) {
        vector<State> next_queue;
        
        for (const auto& [y, x, dc] : current_queue) {
            if (mat[y][x] == 'E') {
                cout << time << endl;
                return 0;
            }
            
            for (int i = 0; i < 5; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny >= 0 && ny < n && nx >= 0 && nx < m && mat[ny][nx] != '#') {
                    int new_damage = dc;
                    
                    // Update damage count
                    if (mat[ny][nx] == '.' || mat[ny][nx] == 'E') {
                        new_damage += c;
                    } else {
                        new_damage -= k;
                    }
                    
                    // Check if damage is too high
                    if (new_damage >= 100) {
                        continue;
                    }
                    
                    // Ensure damage isn't negative
                    if (new_damage < 0) {
                        new_damage = 0;
                    }
                    
                    // If this path has lower damage, add to queue
                    if (new_damage < visited[ny][nx]) {
                        visited[ny][nx] = new_damage;
                        next_queue.emplace_back(ny, nx, new_damage);
                    }
                }
            }
        }
        
        current_queue = std::move(next_queue);
        time++;
    }
    
    cout << -1 << endl;
    return 0;
}