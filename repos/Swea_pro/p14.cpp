#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
//No. 14 0/1 Knapsack

int N, K;
int dp[101][1001];
vector<int> value, cost;

int re_dp(int idx, int left) {
	if (left < 0)
		return -1e9;
	if (idx == N)
		return 0;
	if (dp[idx][left] != -1)
		return dp[idx][left];

	int& ret = dp[idx][left];
	ret = max(re_dp(idx + 1, left), re_dp(idx + 1, left - value[idx]) + cost[idx]);
	return ret;
}

int solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> K;

	value = vector<int>(N);
	cost = vector<int>(N);

	for (int i = 0; i < N; i++)
		cin >> value[i] >> cost[i];

	return re_dp(0, K);
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