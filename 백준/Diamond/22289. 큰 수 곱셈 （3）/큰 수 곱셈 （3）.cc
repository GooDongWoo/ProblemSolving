#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

typedef complex<double> cpx;
const double PI = acos(-1);

void fft(vector<cpx>& a, bool invert) {
    int n = a.size();
    
    // 비트 반전 순서 바꾸기
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }

    // Butterfly Operation
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cpx wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cpx w(1);
            for (int j = 0; j < len / 2; j++) {
                cpx u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    // 역변환시 n으로 나눔
    if (invert) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(const vector<int>& a, const vector<int>& b, vector<int>& res) {
    vector<cpx> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    
    // 다항식 곱셈을 위해 크기를 2의 거듭제곱 꼴로 맞춰줌 (두 길이 합보다 커야 함)
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    
    fa.resize(n);
    fb.resize(n);

    // FFT 실행 (계수 -> 점-값)
    fft(fa, false);
    fft(fb, false);

    // 점별 곱셈
    for (int i = 0; i < n; i++) fa[i] *= fb[i];

    // Inverse FFT 실행 (점-값 -> 계수)
    fft(fa, true);

    // 결과를 정수로 변환 및 캐리 처리
    res.resize(n);
    for (int i = 0; i < n; i++) {
        res[i] = (int)(fa[i].real() + 0.5); // 반올림하여 정수화
    }

    // Carry 처리
    for (int i = 0; i < n - 1; i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout.tie(NULL);
    
    string s1, s2;
    cin >> s1 >> s2;

    if (s1 == "0" || s2 == "0") {
        cout << "0";
        return 0;
    }

    vector<int> a, b;
    for (int i = s1.size() - 1; i >= 0; i--) a.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--) b.push_back(s2[i] - '0');

    vector<int> result;
    multiply(a, b, result);

    int i = result.size() - 1;
    while (i > 0 && result[i] == 0) i--;

    for (; i >= 0; i--) {
        cout << result[i];
    }

    return 0;
}