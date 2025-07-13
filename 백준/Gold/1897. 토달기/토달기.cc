#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int D;
string st, tmp, ans;
vector<string> dict[82];
queue<string> q;
unordered_set<string> visited;

bool canInsertOne(const string& cur, const string& target) {
    if (target.size() != cur.size() + 1) return false;

    int curIdx = 0, targetIdx = 0;
    bool inserted = false;

    while (curIdx < cur.size() && targetIdx < target.size()) {
        if (cur[curIdx] == target[targetIdx]) {
            curIdx++;
            targetIdx++;
        }
        else {
            if (inserted) return false; 
            inserted = true;
            targetIdx++;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D >> st;
    ans = st;

    rep(i, 0, D) {
        cin >> tmp;
        dict[tmp.size()].push_back(tmp);
    }

    rep(i, 0, 82) {
        sort(dict[i].begin(), dict[i].end());
    }

    visited.insert(st);
    q.push(st);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        int nextLen = cur.size() + 1;

        for (const string& candidate : dict[nextLen]) {
            if (visited.count(candidate)) continue;

            if (canInsertOne(cur, candidate)) {
                if (candidate.size() > ans.size()) {
                    ans = candidate;
                }

                visited.insert(candidate);
                q.push(candidate);
            }
        }
    }

    cout << ans << endl;
    return 0;
}