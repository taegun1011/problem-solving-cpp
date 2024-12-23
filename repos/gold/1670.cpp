#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define MOD 987654321

ll dp[10001];

ll re_dp(int n) {
	if (n == 0)
		return 1;
	if (n <= 4)
		return n / 2;
	if (dp[n] != -1)
		return dp[n];
	ll& ret = dp[n] = 0;
	for (int i = 2; i <= n; i += 2) {
		ret = (ret + re_dp(i - 2) * re_dp(n - i)) % MOD;
	}

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