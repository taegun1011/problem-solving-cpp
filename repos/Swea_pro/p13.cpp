#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 13 최장 공통 부분 수열

int dp[1001][1001];
string A, B;

int re_dp(int a, int b) {
	if (a == A.length() || b == B.length())
		return 0;
	if (dp[a][b] != -1)
		return dp[a][b];
	int& ret = dp[a][b];
	if (A[a] == B[b])
		ret = re_dp(a + 1, b + 1) + 1;
	else
		ret = max(re_dp(a + 1, b), re_dp(a, b + 1));
	return ret;
}

int solve() {
	memset(dp, -1, sizeof(dp));

	cin >> A >> B;

	return re_dp(0, 0);
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