#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int solve(int n) {
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i / 2] + 1, dp[i]);
		if (i % 3 == 0)
			dp[i] = min(dp[i / 3] + 1, dp[i]);
	}

	return dp[n];
}

int main() {
	int N;
	cin >> N;

	cout << solve(N) << endl;
}