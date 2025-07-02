#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	fastio;
	string a;
	cin >> a;
	if (a == "fdsajkl;" || a == "jkl;fdsa") { printf("in-out"); }
	else if (a == "asdf;lkj" || a == ";lkjasdf") { printf("out-in"); }
	else if (a == "asdfjkl;") { printf("stairs"); }
	else if (a == ";lkjfdsa") { printf("reverse"); }
	else { printf("molu"); }
}