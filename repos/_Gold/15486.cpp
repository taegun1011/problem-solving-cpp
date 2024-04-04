#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF -1e9

vector<int> T, P;

int dp[1500001];
int N;

int re_dp(int day) {
	if (day > N + 1)
		return INF;
	if (day == N + 1)
		return 0;

	if (dp[day] != -1)
		return dp[day];

	int& ret = dp[day];
	ret = max(re_dp(day + 1), re_dp(day + T[day]) + P[day]);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	T = vector<int>(N + 1);
	P = vector<int>(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];

	cout << re_dp(1) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}