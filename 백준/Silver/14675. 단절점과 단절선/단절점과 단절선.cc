#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <tuple>
using namespace std;

int N, Q, ps[100000][2];
vector<vector<int>> adjv(100000);

int main() {
    fastio;
    cin >> N;
    rep(i, 0, N-1) {
        int a, b;
        cin >> a >> b;a--;b--;
        adjv[a].push_back(b);
        adjv[b].push_back(a);
        ps[i][0] = a;ps[i][1] = b;
    }

    cin >> Q;
    rep(i, 0, Q) {
        int a, b;
        cin >> a >> b;b--;
        if (a == 1) {
            if (adjv[b].size() == 1) printf("no\n");
            else printf("yes\n");
        }
        else {
            int start = ps[b][0],end = ps[b][1];
            printf("yes\n");
        }
    }

    return 0;
}