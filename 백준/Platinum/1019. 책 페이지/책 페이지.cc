#include <iostream>
using namespace std;

long long ans[10];

// digit_val: 현재 자릿수의 가중치
void count_digits(long long n, long long digit_val) {
    while (n > 0) {
        ans[n % 10] += digit_val;
        n /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    if (!(cin >> N)) return 0;

    long long start = 1;
    long long end = N;
    long long digit_val = 1; 

    while (start <= end) {
        // 1. start의 일의 자리가 0이 될 때까지 
        while (start % 10 != 0 && start <= end) {
            count_digits(start, digit_val);
            start++;
        }

        // 2. end의 일의 자리가 9가 될 때까지
        while (end % 10 != 9 && start <= end) {
            count_digits(end, digit_val);
            end--;
        }

        if (start > end) break;

        // 3. start와 end 사이
        long long cnt = (end / 10 - start / 10 + 1);
        
        for (int i = 0; i < 10; i++) {
            ans[i] += cnt * digit_val;
        }

        // 4. 다음
        start /= 10;
        end /= 10;
        digit_val *= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << (i == 9 ? "" : " ");
    }
    cout << "\n";

    return 0;
}