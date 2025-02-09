#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define fi first
#define se second
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int N, a, b, c;
vector <pair<int, int>> arr;

int GCD(int a, int b) {
    if (a * b == 0) return (a != 0) ? a : b;
    if (a < b) swap(a, b);
    if (a % b == 0) return b;
    return GCD(b, a % b);
}

int flbs(int a) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a <= arr[mid].fi) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}

int fubs(int a) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a < arr[mid].fi) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}
int slbs(int a, int start, int end) {
    end--;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a <= arr[mid].se) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}
int subs(int a, int start, int end) {
    end--;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a < arr[mid].se) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    rep(i, 0, N) {
        cin >> a >> b >> c;
        if (a < 0) {
            a *= -1; b *= -1;
        }
        else if (a == 0 && b < 0) b *= -1;
        int gcd = GCD(abs(a), abs(b));
        arr.push_back({ a / gcd, b / gcd });
    }
    sort(arr.begin(), arr.end());

    int idx = 0;
    LL cnter = 0;
    while (idx < arr.size()) {
        a = arr[idx].fi; b = arr[idx].se;
        int ms = flbs(a); int me = fubs(a);
        int lo = slbs(b, ms, me); int up = subs(b, ms, me);
        cnter += ((LL)N - (up - lo)) * (up - lo);
        idx += (up - lo);
    }
    printf("%lld\n", cnter/2);
    return 0;
}