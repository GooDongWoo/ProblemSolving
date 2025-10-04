#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;


int T, N;
bool Flag;

struct Node {
	bool IsEnd;
	Node* child[10];
	Node() :IsEnd(false) {
		rep(i, 0, 10) {
			child[i] = nullptr;
		}
	}
};
struct Trie {
	Node head;
	Trie() {
	}
	void insert(string& word, Node* cur, int idx) {
		Node* nxtp;
		if (cur->child[word[idx] - '0']) {
			nxtp = cur->child[word[idx] - '0'];
		}
		else {
			nxtp = new Node();
			cur->child[word[idx] - '0'] = nxtp;
		}
		if (nxtp->IsEnd) {
			Flag = 0;
		}
		if (idx == word.size() - 1) {
			nxtp->IsEnd = true;
			int tFlag = 1;
			rep(i, 0, 10) {
				if (nxtp->child[i]) {
					Flag = 0;
				}
			}
		}
		else {
			insert(word, nxtp, idx + 1);
		}
	}
};


int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N;
		Trie trie = Trie();
		Flag = 1;
		rep(i, 0, N) {
			string word;
			cin >> word;
			trie.insert(word, &trie.head, 0);
		}
		if (Flag) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}