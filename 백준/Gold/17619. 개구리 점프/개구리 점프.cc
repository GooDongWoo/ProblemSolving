#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

bool cmp(const vector<int>&i1, const vector<int>&i2) {
    if (i1[0] == i2[0]) return i1[1] > i2[1];
    else return i1[0] < i2[0];
}
int n, q, s, e, tmp, cs, ce, dat[100000], idx;
int main() {
    fastio;
    cin >> n >> q;
    vector <vector<int>> a;
    rep(i, 0, n) {
        cin >> s >> e >> tmp;
        a.push_back(vector<int>{s, e, i});
    }
    sort(a.begin(), a.begin() + n, cmp);

    dat[a[0][2]] = idx;
    cs = a[0][0], ce = a[0][1];
    rep(i, 1, n) {
        if (cs <= a[i][0] && a[i][0] <= ce) {
            ce = max(ce, a[i][1]);
            dat[a[i][2]] = idx;
        }
        else {
            cs = a[i][0];ce = a[i][1];
            dat[a[i][2]] = ++idx;
        }
    }
    rep(i, 0, q) {
        cin >> s >> e;
        if (dat[s - 1] == dat[e - 1]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}