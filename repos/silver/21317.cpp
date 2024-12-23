#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[21][2];
int N, K;
vector<int> sj, bj;

int re_dp(int idx, int used) {
	if (idx == N - 1)
		return 0;

	if (dp[idx][used] != -1)
		return dp[idx][used];

	int& ret = dp[idx][used];
	//작은 점프
	ret = re_dp(idx + 1, used) + sj[idx];

	//큰 점프
	if (idx + 2 < N)
		ret = min(ret, re_dp(idx + 2, used) + bj[idx]);

	//매우 큰 점프
	if (idx + 3 < N && !used)
		ret = min(ret, re_dp(idx + 3, 1) + K);

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;

	sj = vector<int>(N - 1);
	bj = vector<int>(N - 1);
	for (int i = 0; i < N - 1; i++)
		cin >> sj[i] >> bj[i];

	cin >> K;

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