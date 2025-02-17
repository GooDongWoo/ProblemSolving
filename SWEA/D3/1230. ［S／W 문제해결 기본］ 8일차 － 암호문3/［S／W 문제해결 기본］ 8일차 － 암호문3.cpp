#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, Q;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int tmp;
		cin >> N;
		vector <int> arr;
		rep(i, 0, N) {
			cin >> tmp;
			arr.push_back(tmp);
		}
		cin >> Q;
		rep(i, 0, Q) {
			char opnd;
			int x, y;
			cin >> opnd;
			if (opnd == 'I') {
				int cnt = 0;
				cin >> x >> y;
				rep(j, 0, y) {
					int s;
					cin >> s;
					arr.insert(arr.begin() + x + (cnt++), s);
				}
			}
			else if (opnd == 'D') {
				int cnt = 0;
				cin >> x >> y;
				rep(j, 0, y) {
					arr.erase(arr.begin() + x);
				}
			}
			else{
				int cnt = 0;
				cin >> y;
				rep(j, 0, y) {
					int s;
					cin >> s;
					arr.push_back(s);
				}
			}
		}
		printf("#%d ", test_case);
		rep(i, 0, 10) printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}