#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int mod = 1000000000;
int dp[1000001];

int re_dp(int cur) {
	if (cur <= 3)
		return cur - 1;

	if (dp[cur] != -1)
		return dp[cur];

	int& ret = dp[cur];

	ret = (1ll * (cur - 1) * (re_dp(cur - 1) + re_dp(cur - 2))) % mod;

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	cout << re_dp(N) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}