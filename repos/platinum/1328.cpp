#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

int mod = 1000000007;

void solve() {
	int N, L, R;
	cin >> N >> L >> R;

	ll dp[101][101][101];
	memset(dp, 0, sizeof(dp));
	dp[1][1][1] = 1;
	for (int i = 1; i < N; i++) {
		for (int l = 1; l <= i; l++) {
			for (int r = 1; r <= i; r++) {
				dp[i + 1][l + 1][r] = (dp[i + 1][l + 1][r] + dp[i][l][r]) % mod;
				dp[i + 1][l][r + 1] = (dp[i + 1][l][r + 1] + dp[i][l][r]) % mod;
				dp[i + 1][l][r] = (dp[i + 1][l][r] + dp[i][l][r] * (i - 1)) % mod;
			}
		}
	}

	cout << dp[N][L][R] << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}