#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

//No. 25 ระบา ภฬบฅฦฎ
long long solve() {
	long long N;
	cin >> N;

	long long s = 0, e = 2e9, m;

	//SSSEBBB
	while (s <= e) {
		m = s + (e - s) / 2;
		long long chk = m * (m + 1) / 2;
		if (chk == N)
			return m;
		else if (chk < N)
			s = m + 1;
		else
			e = m - 1;
	}
	return -1;
}

int main() {
	FASTIO;
	int TC;
	//TC = 1;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		printf("#%d %lld\n", tc, solve());
	}
}