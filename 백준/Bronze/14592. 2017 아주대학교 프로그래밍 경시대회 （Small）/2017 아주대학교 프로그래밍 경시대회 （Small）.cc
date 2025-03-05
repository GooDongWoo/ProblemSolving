#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

typedef struct Item {
    int score, num, time,idx;
    bool operator<(const Item& o)const {
        return (tie(score, o.num, o.time) < tie(o.score, num, time));
    }
};
int N;
Item arr[3];

int main() {
    fastio;
    cin >> N;
    rep(i, 0, N) {
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = { a,b,c,i+1 };
    }
    sort(arr, arr + N);
    printf("%d\n", arr[N-1].idx);
    return 0;
}