#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
ll dp[101][101];

bool invalid[101][101][2];

int N, M;
ll re_dp(int n, int m) {
	if (n > N || m > M)
		return 0;
	if (n == N && m == M)
		return 1;
	if (dp[n][m] != -1)
		return dp[n][m];

	ll& ret = dp[n][m] = 0;

	if (!invalid[n][m][0])
		ret += re_dp(n + 1, m);
	if (!invalid[n][m][1])
		ret += re_dp(n, m + 1);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;

	int K;
	cin >> K;
	while (K--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a - c)
			invalid[min(a, c)][b][0] = true;
		else
			invalid[a][min(b, d)][1] = true;
	}

	cout << re_dp(0, 0) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}