#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

struct Student {
    int r0, r1, r2;

    bool operator<(const Student& other) const {
        return r0 < other.r0;
    }
};

int N;
std::vector<int> segTree;
std::vector<Student> students;

void update(int node, int start, int end, int qIdx, int val) {
    if (qIdx < start || end < qIdx) return;
    if (start == end) {
        segTree[node] = std::min(segTree[node], val);
        return;
    }
    int mid = (start + end) / 2;
    update(2 * node, start, mid, qIdx, val);
    update(2 * node + 1, mid + 1, end, qIdx, val);
    segTree[node] = std::min(segTree[2 * node], segTree[2 * node + 1]);
}

int query(int node, int start, int end, int qStart, int qEnd) {
    if (qEnd < start || end < qStart || qStart > qEnd) return INF;
    if (qStart <= start && end <= qEnd) return segTree[node];
    int mid = (start + end) / 2;
    return std::min(query(2 * node, start, mid, qStart, qEnd), 
                    query(2 * node + 1, mid + 1, end, qStart, qEnd));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N;

    students.resize(N);
    for (int i = 0; i < N; ++i) {
        int id;
        std::cin >> id;
        students[id - 1].r0 = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        int id;
        std::cin >> id;
        students[id - 1].r1 = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        int id;
        std::cin >> id;
        students[id - 1].r2 = i + 1;
    }
    
    std::sort(students.begin(), students.end());

    segTree.assign(4 * N, INF);
    
    int nonInferiorCount = 0;
    for (int i = 0; i < N; ++i) {
        int minR2 = query(1, 1, N, 1, students[i].r1 - 1);
        
        if (minR2 > students[i].r2) {
            nonInferiorCount++;
        }
        
        update(1, 1, N, students[i].r1, students[i].r2);
    }

    std::cout << nonInferiorCount;

    return 0;
}