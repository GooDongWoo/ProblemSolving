#include <cstdio>
#include <vector>

using namespace std;

/**
 * Fast I/O: fread를 사용하여 버퍼 단위로 데이터를 읽어들입니다.
 * cin/cout 대비 수배~수십 배 빠릅니다.
 */
class FastReader {
    char buf[1 << 19];
    int pos, len;
public:
    FastReader() : pos(0), len(0) {}
    char read() {
        if (pos == len) {
            pos = 0;
            len = fread(buf, 1, sizeof(buf), stdin);
            if (!len) return EOF;
        }
        return buf[pos++];
    }
    int readInt() {
        int x = 0;
        char ch = read();
        while (ch < '0' || ch > '9') {
            if (ch == EOF) return -1;
            ch = read();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = read();
        }
        return x;
    }
} rd;

/**
 * Fast Output: fwrite를 사용하여 버퍼 단위로 출력합니다.
 */
class FastWriter {
    char buf[1 << 19];
    int pos;
public:
    FastWriter() : pos(0) {}
    ~FastWriter() { flush(); }
    void flush() {
        if (pos) fwrite(buf, 1, pos, stdout);
        pos = 0;
    }
    void writeInt(int x) {
        if (x == 0) { writeChar('0'); return; }
        char s[12];
        int n = 0;
        while (x) { s[n++] = x % 10 + '0'; x /= 10; }
        while (n--) writeChar(s[n]);
    }
    void writeChar(char c) {
        if (pos == sizeof(buf)) flush();
        buf[pos++] = c;
    }
} wr;

// 문제 조건에 따른 최대 크기 설정 (예: N=10만, M=5만)
const int MAXN = 100005;
const int MAXM = 500005;

int head[MAXN], nxt[MAXM], to[MAXM], edgeIdx;
int inCnt[MAXN], ans[MAXN], q[MAXN];

void addEdge(int u, int v) {
    to[edgeIdx] = v;
    nxt[edgeIdx] = head[u];
    head[u] = edgeIdx++;
}

int main() {
    int N = rd.readInt();
    int M = rd.readInt();
    if (N == -1) return 0;

    // 초기화
    for (int i = 1; i <= N; i++) head[i] = -1;
    edgeIdx = 0;

    for (int i = 0; i < M; i++) {
        int u = rd.readInt();
        int v = rd.readInt();
        addEdge(u, v);
        inCnt[v]++;
    }

    int headQ = 0, tailQ = 0;
    for (int i = 1; i <= N; i++) {
        if (inCnt[i] == 0) q[tailQ++] = i;
    }

    int time = 0;
    while (headQ < tailQ) {
        int size = tailQ - headQ;
        time++;
        while (size--) {
            int cur = q[headQ++];
            ans[cur] = time;
            for (int i = head[cur]; i != -1; i = nxt[i]) {
                if (--inCnt[to[i]] == 0) {
                    q[tailQ++] = to[i];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        wr.writeInt(ans[i]);
        wr.writeChar(i == N ? '\n' : ' ');
    }

    return 0;
}