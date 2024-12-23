#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int dp[21][21][21];
vector<int> arr;

int N, M;
int re_dp(int idx, int left, int right) {
	if (idx == M)
		return 0;
	if (dp[idx][left][right] != -1)
		return dp[idx][left][right];
	int& ret = dp[idx][left][right];
	if (arr[idx] <= left)
		ret = re_dp(idx + 1, arr[idx], right) + left - arr[idx];
	else if (arr[idx] >= right) {
		ret = re_dp(idx + 1, left, arr[idx]) + arr[idx] - right;
	}
	else {
		ret = min(re_dp(idx + 1, arr[idx], right) + arr[idx] - left, re_dp(idx + 1, left, arr[idx]) + right - arr[idx]);
	}

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N;
	int a, b;
	cin >> a >> b;

	cin >> M;
	arr.resize(M);
	for (int& x : arr)
		cin >> x;

	cout << re_dp(0, a, b) << endl;
}

int main() {
	FASTIO;
	int TC;
	TC = 1;
	//cin >> TC;
	while (TC--)
		solve();
}