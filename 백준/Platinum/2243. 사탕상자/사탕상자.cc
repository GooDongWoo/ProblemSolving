#include <iostream>
#include <vector>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)

const int MAX_FLAVOR = 1e6;

class SegmentTree {
public:
    vector<long long> tree;
    int size;
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    // 세그먼트 트리 업데이트 함수
    void update(int node, int start, int end, int idx, int val) {
        if (idx < start || idx > end) return;

        if (start == end) {
            tree[node] += val;
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // 특정 순위의 사탕 맛을 찾는 쿼리 함수
    int query(int node, int start, int end, int rank) {
        if (start == end) return start;

        int mid = (start + end) / 2;
        long long left_sum = tree[node * 2];

        if (rank <= left_sum) 
            return query(node * 2, start, mid, rank);
        else 
            return query(node * 2 + 1, mid + 1, end, rank - left_sum);
    }

    // 구간 합을 구하는 함수
    long long get_sum(int node, int start, int end, int left, int right) {
        if (left > end || right < start) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        long long left_sum = get_sum(node * 2, start, mid, left, right);
        long long right_sum = get_sum(node * 2 + 1, mid + 1, end, left, right);
        return left_sum + right_sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    SegmentTree segTree(MAX_FLAVOR);

    rep(i, 0, n) {
        int A;
        cin >> A;
        if (A == 1) {
            // 사탕을 꺼내는 경우
            int B;
            cin >> B;
            int taste = segTree.query(1, 1, MAX_FLAVOR, B);
            printf("%d\n", taste);

            // 해당 맛의 사탕 하나 제거
            segTree.update(1, 1, MAX_FLAVOR, taste, -1);
        }
        else {
            // 사탕을 넣거나 빼는 경우
            int B, C;
            cin >> B >> C;

            // B 맛의 사탕을 C개 추가/제거
            segTree.update(1, 1, MAX_FLAVOR, B, C);
        }
    }

    return 0;
}