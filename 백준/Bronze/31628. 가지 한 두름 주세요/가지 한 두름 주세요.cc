#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool canMakeBundle(const vector<vector<string>>& grid) {
    const int rows = 10;
    const int cols = 10;
    
    // 각 행 확인
    for (int r = 0; r < rows; r++) {
        map<string, int> colorCount;
        
        for (int c = 0; c < cols; c++) {
            colorCount[grid[r][c]]++;
        }
        
        // 이 행에서 어떤 색깔이 정확히 10번 나타나는지 확인
        for (const auto& pair : colorCount) {
            if (pair.second == 10) {
                return true;
            }
        }
    }
    
    // 각 열 확인
    for (int c = 0; c < cols; c++) {
        map<string, int> colorCount;
        
        for (int r = 0; r < rows; r++) {
            colorCount[grid[r][c]]++;
        }
        
        // 이 열에서 어떤 색깔이 정확히 10번 나타나는지 확인
        for (const auto& pair : colorCount) {
            if (pair.second == 10) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    vector<vector<string>> grid(10, vector<string>(10));
    
    // 입력 받기
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> grid[i][j];
        }
    }
    
    // 결과 출력
    cout << (canMakeBundle(grid) ? "1" : "0") << endl;
    
    return 0;
}