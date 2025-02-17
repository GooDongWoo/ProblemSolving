#include<iostream>
#include <cstring>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int N, M;


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N >> M;
		int target = (1 << N) - 1;
		if ((M & target) == target) printf("#%d ON\n", test_case);
		else printf("#%d OFF\n", test_case);
	}
	return 0;
}