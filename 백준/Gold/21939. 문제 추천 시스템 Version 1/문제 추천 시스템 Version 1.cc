#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX_P = 100002;

int ans[MAX_P];
priority_queue<pair<int, int>> maxq; 
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq; // 오름차순

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while(N--) {
        int p, l;
        cin >> p >> l;
        ans[p] = l;
        maxq.push({l, p});
        minq.push({l, p});
    }

    int M;
    cin >> M;
    while(M--) {
        string cmd;
        cin >> cmd;

        if (cmd[0] == 'a') { // add
            int p, l;
            cin >> p >> l;
            ans[p] = l;
            maxq.push({l, p});
            minq.push({l, p});
        }
        else if (cmd[0] == 's') { 
            int p;
            cin >> p;
            ans[p] = 0; 
        }
        else { 
            int x;
            cin >> x;
            if (x == 1) {
                while (!maxq.empty() && ans[maxq.top().second] != maxq.top().first) {
                    maxq.pop();
                }
                cout << maxq.top().second << '\n';
            }
            else {
                while (!minq.empty() && ans[minq.top().second] != minq.top().first) {
                    minq.pop();
                }
                cout << minq.top().second << '\n';
            }
        }
    }
    return 0;
}