#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 9901

int dp[100001][3];

int re_dp(int cur, int type) {
	if (cur == 1)
		return 1;
	
	if (dp[cur][type] != -1)
		return dp[cur][type];

	int& ret = dp[cur][type];

	ret = re_dp(cur - 1, 0);
	if (type != 1)
		ret += re_dp(cur - 1, 1);
	if (type != 2)
		ret += re_dp(cur - 1, 2);
	ret %= MOD;
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	cout << (re_dp(N, 0) + re_dp(N, 1) + re_dp(N, 2)) % MOD << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}