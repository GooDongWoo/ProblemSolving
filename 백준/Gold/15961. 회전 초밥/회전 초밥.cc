#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <cstdio>
#include <algorithm>

using namespace std;

static char buf[1 << 20];
static int pos, len;

inline char readChar() {
    if (pos == len) {
        pos = 0;
        len = fread(buf, 1, 1 << 20, stdin);
        if (!len) return EOF;
    }
    return buf[pos++];
}

inline int readInt() {
    int x = 0;
    char c = readChar();
    while (c < '0' || c > '9') c = readChar();
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = readChar();
    }
    return x;
}

int n, d, k, c;
int arr[3003000];
int cnt[3001];

int main() {
    n = readInt(); d = readInt(); k = readInt(); c = readInt();

    for (int i = 0; i < n; ++i) {
        arr[i] = readInt();
    }
    for (int i = 0; i < k; ++i) {
        arr[i + n] = arr[i];
    }

    int current_distinct = 1;
    cnt[c] = 1;

    for (int i = 0; i < k; ++i) {
        if (cnt[arr[i]]++ == 0) {
            current_distinct++;
        }
    }

    int max_distinct = current_distinct;

    for (int i = 0; i < n - 1; ++i) {
        if (--cnt[arr[i]] == 0) {
            current_distinct--;
        }
        if (cnt[arr[i + k]]++ == 0) {
            current_distinct++;
        }
        if (current_distinct > max_distinct) {
            max_distinct = current_distinct;
        }
    }

    printf("%d\n", max_distinct);

    return 0;
}