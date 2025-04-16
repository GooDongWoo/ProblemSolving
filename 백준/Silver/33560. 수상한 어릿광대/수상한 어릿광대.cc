#include <iostream>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define LL long long

using namespace std;

int N, point, timer, tincre, pincre, divs, arr[4], dice;

void pointCal() {
	if (35 <= point && point < 65)
		arr[0]++;
	if (65 <= point && point < 95)
		arr[1]++;
	if (95 <= point && point < 125)
		arr[2]++;
	if (125 <= point)
		arr[3]++;
}
void init() {
	point = 0;
	timer = 0;
	divs = 1;
	pincre = 1;
	tincre = 4;
	return;
}
int main() {
	fastio;
	cin >> N;
	init();
	rep(i, 0, N) {
		if (timer > 240) {
			pointCal();
			init();
		}
		cin >> dice;
		if (dice == 1) {
			pointCal();
			init();
			continue;
		}
		else if (dice == 2) {
			if (pincre > 1)
				pincre /= 2;
			else
				tincre += 2;
		}
		else if (dice == 3) {

		}
		else if (dice == 4) {
			timer += 56;
		}
		else if (dice == 5) {
			if (tincre > 1)
				tincre -= 1;
		}
		else if (dice == 6) {
			if (pincre < 32)
				pincre *= 2;
		}
		timer += tincre;
		point += pincre;
	}
	rep(i, 0, 4)
		printf("%d\n", arr[i]);
}