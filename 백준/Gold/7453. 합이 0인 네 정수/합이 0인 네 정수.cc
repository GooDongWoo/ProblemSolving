#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 4000;
int mat[4][MAX_N];
int l1[MAX_N * MAX_N], l2[MAX_N * MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    // 입력 받기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[j][i];
        }
    }
    
    // 두 개의 배열 만들기
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            l1[idx] = mat[0][i] + mat[1][j];
            l2[idx] = mat[2][i] + mat[3][j];
            idx++;
        }
    }
    
    // 정렬
    sort(l1, l1 + (n*n));
    sort(l2, l2 + (n*n));
    
    long long cnter = 0;
    
    // 이분 탐색으로 개수 세기
    for (int i = 0; i < n*n; i++) {
        int target = l1[i];
        int* left = lower_bound(l2, l2 + (n*n), -target);
        int* right = upper_bound(l2, l2 + (n*n), -target);
        cnter += (right - left);
    }
    
    cout << cnter << '\n';
    
    return 0;
}