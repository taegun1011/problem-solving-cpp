	#define _CRT_SECURE_NO_WARNINGS
	#include <bits/stdc++.h>
	using namespace std;

	#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
	#define ll long long

	ll dp[101][1 << 10][10];

	int main() {
		FASTIO;

		int N;
		cin >> N;
		ll div = 1000000000;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i <= 9; i++)
			dp[1][1 << i][i] = 1;

		for (int i = 1; i < N; i++) {

			for (int j = 1; j < (1 << 10); j++) {

				for (int k = 0; k <= 9; k++) {

					if ((j & (1 << k)) == 0) continue;
					if (dp[i][j][k] < 0) continue;

					if (k + 1 <= 9) {
						ll& up = dp[i + 1][j | (1 << (k + 1))][k + 1];
						up = up < 0 ? dp[i][j][k] : up + dp[i][j][k];
						up %= div;
					}

					if (k - 1 >= 0) {
						ll& down = dp[i + 1][j | (1 << (k - 1))][k - 1];
						down = down < 0 ? dp[i][j][k] : down + dp[i][j][k];
						down %= div;
					}
				}
			}
		}

		ll res = 0;

		for (int i = 1; i <= 9; i++) {
			if (dp[N][(1 << 10) - 1][i] > 0)
				res = (res + dp[N][(1 << 10) - 1][i]) % div;
		}

		cout << res << endl;
	}