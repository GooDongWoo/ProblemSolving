#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;

int N, arr[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int tot = 0;
    rep(i, 0, N) {
        cin >> arr[i];
        tot += arr[i];
    }
    if (tot == 0)
        printf("divide by zero");
    else
        printf("1.00");
    return 0;
}