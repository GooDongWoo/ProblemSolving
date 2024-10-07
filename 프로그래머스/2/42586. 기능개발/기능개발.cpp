#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <pair <int,int>> q;
    int cnt;
    for (int i = 0; i < speeds.size(); i++) {
        q.push(make_pair(progresses[i], speeds[i]));
    }
    while (q.size() != 0) {
        for (int i = 0; i < q.size();i++) {
            int a, b;
            a=q.front().first;
            b=q.front().second;
            a += b;
            q.pop();
            q.push(make_pair(a, b));
        }
        cnt = 0;
        while (q.size()>0 and q.front().first >= 100) {
            q.pop();
            cnt++;
            }
        if (cnt != 0) {
            answer.push_back(cnt);
        }
    }
    return answer;
}