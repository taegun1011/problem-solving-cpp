#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[1001][1001];

int N, M;
vector<int> arr;

int re_dp(int idx, int left) {
	if (idx == N)
		return 0;

	if (dp[idx][left] != -1)
		return dp[idx][left];

	int& ret = dp[idx][left];

	ret = left * left + re_dp(idx + 1, M - arr[idx]);

	if (left >= arr[idx] + 1)
		ret = min(ret, re_dp(idx + 1, max(left - arr[idx] - 1, 0)));

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	arr = vector<int>(N);
	for (int& x : arr)
		cin >> x;

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