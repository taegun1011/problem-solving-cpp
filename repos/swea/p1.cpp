#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 1 새로운 불면증 치료법
int solve() {
	int N;
	cin >> N;

	int field = 0, ans = 0;
	while (field + 1 != (1 << 10)) {
		ans += N;
		int tmp = ans;
		while (tmp) {
			field |= 1 << (tmp % 10);
			tmp /= 10;
		}
	}

	return ans;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %d\n", tc, solve());
	}
}