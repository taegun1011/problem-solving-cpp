#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000000

int dp[1000001][21];

int re_dp(int left, int cur) {
	if (left < 0)
		return 0;

	if (left == 0)
		return 1;

	if (dp[left][cur] != -1)
		return dp[left][cur];

	int& ret = dp[left][cur] = 0;

	int num = pow(2, cur);
	while (num) {
		ret = (ret + re_dp(left - num, cur)) % MOD;
		cur--;
		num >>= 1;
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	int N;
	cin >> N;

	int n = 1, e = 0;
	while (n <= N) {
		n *= 2;
		e++;
	}

	cout << re_dp(N, e - 1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}