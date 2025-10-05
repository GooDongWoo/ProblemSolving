#include <iostream>
#include <string>
#include <vector>

#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

struct Node {
    bool IsEnd;
    Node* child[10];
    Node() : IsEnd(false) {
        rep(i, 0, 10) {
            child[i] = nullptr;
        }
    }
};

class Trie {
private:
    Node* root;

    void clear(Node* node) {
        if (node == nullptr) return;
        rep(i, 0, 10) {
            clear(node->child[i]);
        }
        delete node;
    }

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        clear(root);
    }

    bool insert(const string& word) {
        Node* current = root;
        for (char ch : word) {
            int num = ch - '0';
            if (current->child[num] == nullptr) {
                current->child[num] = new Node();
            }
            current = current->child[num];

            if (current->IsEnd) {
                return false;
            }
        }

        rep(i, 0, 10) {
            if (current->child[i] != nullptr) {
                return false;
            }
        }

        current->IsEnd = true;
        return true;
    }
};

void solve() {
    int N;
    cin >> N;
    Trie trie;
    bool isConsistent = true;
    vector<string> numbers(N);

    rep(i, 0, N) {
        cin >> numbers[i];
    }

    rep(i, 0, N) {
        if (isConsistent && !trie.insert(numbers[i])) {
            isConsistent = false;
        }
    }

    if (isConsistent) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}