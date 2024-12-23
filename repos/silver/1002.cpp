#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

void solve() {
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	int sum = r1 + r2, diff = abs(r1 - r2);
	
	if (sum > d && d > diff) {
		cout << 2 << endl;
	}
	else if (diff == d) {
		if (d == 0)
			cout << -1 << endl;
		else
			cout << 1 << endl;
	}
	else if(sum == d)
		cout << 1 << endl;
	else if (sum < d || diff > d)
		cout << 0 << endl;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	while (TC--)
		solve();
}