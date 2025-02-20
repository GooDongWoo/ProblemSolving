#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
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
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

int N, v[500000], ans;
vector <vector<int>>adjv(500000);

int main() {
    fastio;
    memset(v, -1, sizeof(v));
    cin >> N;
    int a, b;
    rep(i, 0, N - 1) {
        cin >> a >> b; a--; b--;
        adjv[a].push_back(b);
        adjv[b].push_back(a);
    }
    queue<int> q;
    v[0] = 0;
    q.push(0);
    while (q.size()) {
        int p = q.front(); q.pop();
        bool Flag = 1;
        rep(i, 0, adjv[p].size()) {
            if (v[adjv[p][i]] != -1) continue;
            v[adjv[p][i]] = v[p] + 1;
            q.push(adjv[p][i]);
            Flag = 0;
        }
        if (Flag) ans += v[p];
    }
    string res = (ans & 1) ? "Yes" : "No";
    printf("%s\n", res.c_str());
    return 0;
}