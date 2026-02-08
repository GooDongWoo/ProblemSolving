#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

static char buf[1 << 20]; 
static int idx = 0, len = 0;

inline char ReadChar() {
    if (idx == len) {
        len = fread(buf, 1, 1 << 20, stdin);
        idx = 0;
        if (len == 0) return EOF;
    }
    return buf[idx++];
}

inline int ReadInt() {
    int sum = 0;
    char c = ReadChar();
    bool minus = false;
    while (c < '0' || c > '9') {
        if (c == '-') minus = true;
        c = ReadChar();
    }
    while (c >= '0' && c <= '9') {
        sum = sum * 10 + (c - '0');
        c = ReadChar();
    }
    return minus ? -sum : sum;
}

inline char ReadCommand() {
    char c = ReadChar();
    while (c != 'I' && c != 'D') c = ReadChar();
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T = ReadInt();
    while (T--) {
        priority_queue<int> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        unordered_map<int, int> dict;

        int K = ReadInt();
        dict.reserve(K);

        for (int i = 0; i < K; ++i) {
            char cmd = ReadCommand();
            int val = ReadInt();

            if (cmd == 'I') {
                maxq.push(val);
                minq.push(val);
                dict[val]++;
            } else {
                if (val == 1) {
                    while (!maxq.empty() && dict[maxq.top()] == 0) maxq.pop();
                    if (!maxq.empty()) {
                        dict[maxq.top()]--;
                        maxq.pop();
                    }
                } else {
                    while (!minq.empty() && dict[minq.top()] == 0) minq.pop();
                    if (!minq.empty()) {
                        dict[minq.top()]--;
                        minq.pop();
                    }
                }
            }
        }

        while (!maxq.empty() && dict[maxq.top()] == 0) maxq.pop();
        while (!minq.empty() && dict[minq.top()] == 0) minq.pop();

        if (maxq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxq.top() << ' ' << minq.top() << '\n';
        }
    }
    return 0;
}