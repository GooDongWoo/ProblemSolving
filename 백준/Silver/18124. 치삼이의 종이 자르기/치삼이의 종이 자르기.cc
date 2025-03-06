#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

LL N, lcut,mod;
double K;

int main() {
    fastio;
    cin >> N;
    if (N <= 4) {
        if (N == 1) printf("0\n");
        if (N == 2) printf("1\n");
        if (N == 3) printf("3\n");
        if (N == 4) printf("3\n");
        return 0;
    }
    K = log2(N);
    K = K - 1;
    K = floor(K);
    LL nstart = pow(2, K + 1) - 1;
    if (pow(2, K + 1) != N) {
        lcut = N / 2;
        mod = (N % 2 == 0) ? 0 : 1;
    }
    printf("%lld\n", nstart+lcut+mod);
    return 0;
}