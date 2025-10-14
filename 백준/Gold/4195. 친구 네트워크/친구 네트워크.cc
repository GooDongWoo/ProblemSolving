#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define rep(i, a, b) for (int i = a; i < b; ++i)
using LL = long long;
using namespace std;

int T, N, mapper, p[200000], c[200000];
unordered_map<string, int> dict;

void init(int num) {
    rep(i, 0, 2*num) {
        p[i] = i;
        c[i] = 1;
    }
    mapper = 0;
    dict.clear();
    return;
}

int find__(int a) {
    if (p[a] != a) {
        p[a] = find__(p[a]);
    }
    return p[a];
}

void union__(int a, int b) {
    int pa = find__(a);
    int pb = find__(b);
    if (pa == pb) {
        return;
    }
    if (c[pa] < c[pb]) {
        swap(pa, pb);
    }
    p[pb] = pa;
    c[pa] += c[pb];
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin >> T;
    rep(test_case, 1, T + 1) {
        cin >> N;
        init(N);
        rep(i, 0, N) {
            string a, b;
            cin >> a >> b;
            if (dict.count(a) == 0) {
                dict[a] = mapper++;
            }
            if (dict.count(b) == 0) {
                dict[b] = mapper++;
            }
            union__(dict[a], dict[b]);
            cout << c[find__(dict[a])] << '\n';
        }
    }
}